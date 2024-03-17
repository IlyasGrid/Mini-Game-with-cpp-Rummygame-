#include "ListShape.h"

bool ListShape::isEmpty() {
    if(start == nullptr)
        cout << "empty list" << endl;
    return start == nullptr;
}

void ListShape::appendShape(Shape* shape, char where) {

    if (start == nullptr) {
        start = shape;
        end = shape;
        shapeCount++;
    }

    else {
        if (where == 'r' || where == 'R') { // Append at end
            shape->previous = end; 
            end->next = shape;
            end = shape;
            shapeCount++;

            Shape* current = end->previous;          

            while (current != nullptr)
            {
                if (shape->color == current->color) {
                    shape->previousColor = current;
                    current->nextColor = shape;
                    return;
                }
                current = current->previous;
            }


        }
        else if (where == 'l' || where == 'L') { // Append at beginning
            shape->next = start;
            start->previous = shape;
            start = shape;
            shapeCount++;


            Shape* current = start->next;
            
            while (current != nullptr)
            {
                if (shape->color == current->color) {
                    shape->nextColor = current;
                    current->previousColor = shape;
                    return;
                }
                current = current->next;
            }
        }
    }
}


void ListShape::removeShape(Shape* shapeToRemove) {
    if (start == nullptr)
        return; // List is empty

    Shape* current = start;
    Shape* prev = nullptr;

    while (current != nullptr && current != shapeToRemove) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
        return; // Shape to remove not found

    if (prev != nullptr) {
        prev->next = current->next;
    }
    else {
        start = current->next;
    }

    if (current == end) {
        end = prev; // Update end pointer if removing the last shape
    }
    delete current;
    shapeCount--;
}




int ListShape::checkShapes(int *score) {

    if (start == nullptr || start->next == nullptr || start->next->next == nullptr)
        return -1; // Not enough shapes to compare

    Shape* current = start;

    while (current->next->next != nullptr) {

        if (current->color == current->next->color &&
            current->next->next->color == current->color &&
            current->name == current->next->name &&
            current->next->next->name== current->name)

        {
            this->removeShape(current->next->next);
            this->removeShape(current->next);
            this->removeShape(current);

            (*score) += 1000;
            return 3; // Same color and shape for the two previous shapes
        }


        if (current->color == current->next->color &&
            current->next->next->color == current->color)
        {
            this->removeShape(current->next->next);
            this->removeShape(current->next);
            this->removeShape(current);
            (*score) += 300;
            return 1; // Same color for the two previous shapes
        }

        if (current->name == current->next->name &&
            current->next->next->name == current->name)
        {
            this->removeShape(current->next->next);
            this->removeShape(current->next);
            this->removeShape(current);
            (*score) += 300;
            return 2; // Same shape for the two previous shapes
        }

        current = current->next;
    }

    return -1; // No matching condition found
}


void ListShape::printListShape() const{
    Shape* current = start;

    while (current != nullptr) {
        current->printShape();
        current = current->next;
    }
}

void ListShape::shift() {
    if (isEmpty() || shapeCount == 1) {
        // No need to shift if the list is empty or has only one shape
        return;
    }

    // Move the last shape to the beginning
    Shape* lastShape = end;
    end = lastShape->previous;
    end->next = nullptr;

    lastShape->next = start;
    lastShape->previous = nullptr;
    start->previous = lastShape;
    start = lastShape;
}



