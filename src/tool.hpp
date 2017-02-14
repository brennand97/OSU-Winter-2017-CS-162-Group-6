#ifndef TOOL_HPP
#define TOOL_HPP

enum Fight {WIN, LOSE, DRAW};

class Tool
{
protected:
	int strength;
	char type;

public:
	Tool();
	Tool(int strength);
	virtual ~Tool();
	void setStrength(int strength);
	int getStrength() const;
	char getType() const;
	virtual Fight fight(Tool *tool) = 0;
};
#endif
