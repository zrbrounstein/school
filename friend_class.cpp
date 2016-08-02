
class ClassOne{
public:
	ClassOne();

private:
	int size;

	friend class ClassTwo;
};

class ClassTwo{
	friend class ClassOne;

public:
	ClassTwo();
};

ClassTwo::ClassTwo(){
	ClassOne one;
	one.size = 12;
}
