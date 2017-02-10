#ifndef TOOL_HPP
#define TOOL_HPP

enum Fight {WIN, LOSE, DRAW};

class Tool
{
private:
	int strength; 
	char type;

public:
	Tool();
	Tool(int strength);
	virtual ~Tool();
	void setStrength(int strength);
	virtual int fight(Tool *tool) = 0;
};
#endif
