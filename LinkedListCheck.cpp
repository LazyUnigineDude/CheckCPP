#include "LinkedListCheck.h"

void LinkedListCheck::MainProg() {


	NodeS* Head = nullptr;

	Head = new NodeS();

	InitNode(Head, 15);
	PushNodeFront(&Head, 153);
	PushNodeEnd(&Head, 693);

	PrintList(Head);
	PushNodeFront(&Head, 53);
	AddNode(&Head, 693, 62);
	PushNodeEnd(&Head, 637);

	PrintList(Head);
	DeleteNode(&Head, 693);

	PrintList(Head);
	Head = ReverseNode(Head);
	PrintList(Head);

}
