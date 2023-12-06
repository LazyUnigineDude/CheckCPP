#pragma once
// Preset Pattern

struct Product {};
struct Type1 : Product {};
struct Type2 : Product {};


struct Factory { virtual Product Return() = 0; };
struct Type1Factory : Factory { Product Return() override { return Type1(); } };
struct Type2Factory : Factory { Product Return() override { return Type2(); } };

////////////////////////////////////////////////////////////////////////////////////
// Preset Theme Pattern

struct Product1 {};
struct Product1T1 : Product1 {};
struct Product1T2 : Product1 {};
struct Product1T3 : Product1 {};

struct Product2 {};
struct Product2T1 : Product2 {};
struct Product2T2 : Product2 {};
struct Product2T3 : Product2 {};

struct AbstractFactory {
	
	virtual Product1 GetProduct1() = 0;
	virtual Product2 GetProduct2() = 0;
};

class T1 : AbstractFactory {
	Product1 GetProduct1() override { return Product1T1(); }
	Product2 GetProduct2() override { return Product2T1(); }
};

class T2 : AbstractFactory {
	Product1 GetProduct1() override { return Product1T2(); }
	Product2 GetProduct2() override { return Product2T2(); }
};

class T3 : AbstractFactory {
	Product1 GetProduct1() override { return Product1T3(); }
	Product2 GetProduct2() override { return Product2T3(); }
};