#pragma once

class TagCollection
{
public:
	 TagCollection();
	~TagCollection();

public:
	void Add(Tag tags[]);
	void Remove(Tag tags[]);
	
	bool Contains(Tag tag);

private:
	bool _TagList[Tag::End];
};

