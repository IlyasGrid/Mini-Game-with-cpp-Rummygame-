#include "ListShape.h"
#include <iostream>

bool ListShape::isEmpty() const {
	if (start == nullptr)
	{
		return true;
	}
	else {
		return false;
	}
}

void ListShape::appendShapeAtStart(Shape* shape) {

	shape->next = start;
	start->previous = shape;
	start = shape;
	shape->previous = nullptr;


}

void ListShape::appendShapeAtEnd(Shape* shape) {

	end->next = shape;
	shape->previous = end;
	end = shape;
	shape->next = nullptr;

}

void ListShape::appendShape(Shape* shape, char where) {
	if (isEmpty()) {
		start = shape;
		end = shape;
		shape->next = nullptr;
		shape->previous = nullptr;
	}

	if (where == 's' || where == 'S')
		appendShapeAtStart(shape);
	if (where == 'e' || where == 'E')
		appendShapeAtEnd(shape);

	establishShapeConnections();
	shapeCount++;

}

void ListShape::checkShapes(int* score) {

	if (isEmpty() || shapeCount < 3) {
		return;
	}
	Shape* current = start;
	while (current != nullptr && current->next != nullptr && current->next->next != nullptr) {
		bool sameColor = (current->color == current->next->color) && (current->color == current->next->next->color);
		bool sameName = (current->name == current->next->name) && (current->name == current->next->next->name);

		if (sameColor && sameName) {
			(*score) += 1000;
			removeShape(current->next->next);
			removeShape(current->next);
			Shape* temp = current->next;
			removeShape(current);
			current = temp;
		}
		else if (sameColor || sameName) {
			(*score) += 300;
			removeShape(current->next->next);
			removeShape(current->next);
			Shape* temp = current->next;
			removeShape(current);
			current = temp;
		}
		else {
			current = current->next;
		}
	}
}


void ListShape::removeShape(Shape* shape) {
	// Vérifier si la forme existe dans la liste
	if (shape == nullptr || this->isEmpty()) {
		return;
	}

	// Cas 1: La forme à supprimer est la tête de la liste
	if (shape == start) {
		start = shape->next;
		if (start != nullptr) {
			start->previous = nullptr;
		}
		else {
			end = nullptr; // La liste est devenue vide
		}
	}

	// Cas 2: La forme à supprimer est la queue de la liste
	else if (shape == end) {
		end = shape->previous;
		if (end != nullptr) {
			end->next = nullptr;
		}
		else {
			start = nullptr; // La liste est devenue vide
		}
	}
	// Cas 3: La forme à supprimer est dans le milieu de la liste
	else {
		Shape* prev = shape->previous;
		Shape* next = shape->next;
		prev->next = next;
		next->previous = prev;
	}

	// Supprimer les liens de la forme
	shape->previous = nullptr;
	shape->next = nullptr;

	// Libérer la mémoire de la forme si nécessaire
	delete shape;
	shapeCount--;

	establishShapeConnections();
}

void ListShape::printList() const {
	Shape* current = start;
	while (current != nullptr) {
		current->printShape();
		current = current->next;
	}
}

void ListShape::shiftList() {

	if (isEmpty()) {
		return;  // La liste est vide, rien à faire
	}

	// Déplacer la tête vers la queue
	Shape* temp = start;

	start = start->next;

	start->previous = nullptr;
	end->next = temp;
	temp->next = nullptr;
	temp->previous = end;
	end = temp;


	establishShapeConnections();

}


void ListShape::shiftShapesWithSameColor(string color) {
	if (isEmpty()) {
		return;
	}

	Shape* current = start;
	Shape* firstShapeWithColor = nullptr;
	Shape* lastShapeWithColor = nullptr;

	// Find the first and last shape with the given color
	while (current != nullptr) {
		if (current->color == color) {
			if (firstShapeWithColor == nullptr) {
				firstShapeWithColor = current;
			}
			lastShapeWithColor = current;
		}
		current = current->next;
	}

	// If no shape with the given color is found, return
	if (firstShapeWithColor == nullptr) {
		return;
	}

	// Shift the names of shapes with the given color
	current = firstShapeWithColor;
	string temp = current->name;
	Shape* shapeWithTempName = nullptr;

	while (current != nullptr && current != lastShapeWithColor) {

		swap(current->name, lastShapeWithColor->name);

		current = current->nextColor;
	}


	establishShapeConnections();

}

void ListShape::shiftShapesWithSameName(string name) {

	if (isEmpty()) {
		return;
	}

	Shape* current = start;
	Shape* firstShapeWithName = nullptr;
	Shape* lastShapeWithName = nullptr;

	// Find the first and last shape with the given color
	while (current != nullptr) {
		if (current->name == name) {
			if (firstShapeWithName == nullptr) {
				firstShapeWithName = current;
			}
			lastShapeWithName = current;
		}
		current = current->next;
	}

	// If no shape with the given color is found, return
	if (firstShapeWithName == nullptr) {
		return;
	}

	// Shift the names of shapes with the given color
	current = firstShapeWithName;
	string temp = current->color;
	Shape* shapeWithTempName = nullptr;

	while (current != nullptr && current != lastShapeWithName) {

		swap(current->color, lastShapeWithName->color);

		current = current->nextShape;
	}
}


void ListShape::establishShapeConnections() {
	if (isEmpty()) {
		return;
	}

	Shape* current = start;
	while (current != nullptr) {
		current->nextColor = nullptr;
		current->nextShape = nullptr;

		Shape* helper = current->next;
		while (helper != nullptr) {
			if (helper->color == current->color && current->nextColor == nullptr) {
				current->nextColor = helper;
			}

			if (helper->name == current->name && current->nextShape == nullptr) {
				current->nextShape = helper;
			}

			if (current->nextColor != nullptr && current->nextShape != nullptr) {
				break;
			}

			helper = helper->next;
		}

		current = current->next;
	}
}

void ListShape::printShapesByColor(string color) {

	Shape* current = start;
	while (current != nullptr) {
		if (current->color == color)
			break;
		current = current->next;
	}

	while (current != nullptr) {
		current->printShape();
		current = current->nextColor;
	}

}

void ListShape::printShapesByName(string name) {
	Shape* current = start;
	while (current != nullptr) {
		if (current->name == name)
			break;
		current = current->next;
	}

	while (current != nullptr) {
		current->printShape();
		current = current->nextShape;
	}
}
