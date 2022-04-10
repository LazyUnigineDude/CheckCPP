#pragma once

#include <iostream>

class LinkedListCheck
{
public:

	struct NodeS {
		int Data;
		NodeS* Next;
	};

	struct NodeD {
		int Data;
		NodeD* Prev = nullptr;
		NodeD* Next = nullptr;
	};

	void MainProg();

	void InitNode(NodeS* List, int Data) {
		List->Data = Data;
		List->Next = nullptr;
	}

	void InitNode(NodeD* List, int Data) {
		List->Data = Data;
		List->Prev = nullptr;
		List->Next = nullptr;
	}


	void PrintList(NodeS* List) {

		while (List != nullptr)
		{
			std::cout << List->Data << "   ";
			List = List->Next;
		}
		std::cout << "\n";
	}

	NodeS* ReverseNode(NodeS* List){
		
		NodeS* Curr = List, *Prev = nullptr, *Next = nullptr;

		while (Curr != nullptr)
		{
			Next = Curr->Next;
			Curr->Next = Prev;
			Prev = Curr;
			Curr = Next;
		}
		return Prev;
	}

	void PushNodeFront(NodeS** List, int Data) {

		NodeS* _S = nullptr;
		_S = new NodeS();

		_S->Data = Data;
		_S->Next = *List;

		*List = _S;
	}

	void PushNodeFront(NodeS** List, NodeS** Node) {
		
		NodeS* New = *Node;
		*List = *Node;
	}

	void PushNodeEnd(NodeS** List, int Data) {

		NodeS* _S = nullptr;
		_S = new NodeS();

		_S->Data = Data;
		_S->Next = nullptr;

		NodeS* Current = *List;

		while (Current) {
			if (Current->Next == nullptr) { Current->Next = _S; break; }
			Current = Current->Next;
		}

	}

	void PushNodeEnd(NodeS** List, NodeS** Node) {
		NodeS* Current = *List;

		while (Current) {
			if (Current->Next == nullptr) { Current->Next = *Node; break; }
			Current = Current->Next;
		}

	}

	NodeS* SearchNode(NodeS** List, int Data) {

		NodeS* Current = *List;

		while (Current) {

			if (Current->Data == Data) { return Current; break; }

			Current = Current->Next;
		}
		std::cout << "Not Found." << std::endl;
	}
	
	NodeS* SearchNode(NodeS** List, NodeS** Node) {

		//std::unique_ptr<NodeS*> Current = std::make_unique<NodeS*> (*List);
		NodeS* Current = *List;

		while (Current) {

			if (Current == *Node) { return Current; break; }

			Current = Current->Next;
		}
		std::cout << "Not Found." << std::endl;
	}



	void DeleteNode(NodeS** List, int Data) {

		NodeS* _Current1 = *List;
		NodeS* _Current2 = _Current1->Next;

		if (_Current1->Data == Data) {

			*List = _Current1->Next;
			delete _Current1;
		}

		else {
			while (_Current1) {

				if (_Current2->Data == Data) {

					_Current1->Next = _Current2->Next;
					delete _Current2;
					break;
				}

				if (_Current2->Next == nullptr) { std::cout << "Not Found" << std::endl; break; }


				_Current1 = _Current1->Next;
				_Current2 = _Current2->Next;
			}
		}

	}

	void DeleteNode(NodeS** List, NodeS** Node) {

		NodeS* _Current1 = *List;
		NodeS* _Current2 = _Current1->Next;

		if (_Current1 == *Node) {

			*List = _Current1->Next;
			delete Node;
		}

		else {
			while (_Current1) {

				if (_Current2 == *Node) {

					*List = _Current2->Next;
					delete Node;
					break;
				}

				if (_Current2->Next == nullptr) { std::cout << "Not Found" << std::endl; break; }


				_Current1 = _Current1->Next;
				_Current2 = _Current2->Next;
			}
		}
	}

	void AddNode(NodeS** List, int PrevData, int Data) {

		NodeS* Current1 = *List;
		NodeS* Current2 = Current1->Next;

		if (Current1->Data == PrevData) {

			NodeS* New = nullptr;
			New = new NodeS();

			New->Data = Data;
			New->Next = Current2;

			Current1->Next = New;
		}

		else {
			while (Current1) {

				if (Current2->Data == PrevData) {

					NodeS* New = nullptr;
					New = new NodeS();

					New->Data = Data;
					New->Next = Current2->Next;

					Current2->Next = New;
					break;
				}


				Current1 = Current1->Next;
				Current2 = Current2->Next;
			}
		}
	}


	void AddNode(NodeS** List, NodeS** PrevNode, NodeS** NodetoAdd) {

		NodeS* Current1 = *List;
		NodeS* Current2 = Current1->Next;

		if (Current1 == *PrevNode) {

			*NodetoAdd = Current2;
			Current1->Next = *NodetoAdd;
		}

		else {
			while (Current1) {

				if (Current2 == *PrevNode) {
					*NodetoAdd = Current2->Next;
					Current2->Next = *NodetoAdd;
					break;
				}

				Current1 = Current1->Next;
				Current2 = Current2->Next;
			}
		}
	}

	void PrintList(NodeD* List){}
	void PushNodeFront(NodeD** List, int Data) {}
	void PushNodeFront(NodeD** List, NodeD** Node) {}
	void PushNodeEnd(NodeD** List, int Data) {}
	void PushNodeEnd(NodeD** List, NodeD** Node) {}
	void SearchNode(NodeD** List, int Data) {}
	void SearchNode(NodeD** List, NodeD** Node) {}
	void DeleteNode(NodeD** List, int Data) {}
	void DeleteNode(NodeD** List, NodeD** Node) {}
	void AddNode(NodeD** List, int PrevData, int Data) {}
	void AddNode(NodeD** List, NodeD** PrevNode, NodeD** Node) {}

};

