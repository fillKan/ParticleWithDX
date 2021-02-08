#include "DXUT.h"
#include "TagCollection.h"

TagCollection::TagCollection()
{
	memset(_TagList, FALSE, Tag::End);
}

TagCollection::~TagCollection()
{
}

void TagCollection::Add(Tag tags[])
{
	int length = sizeof(tags) / sizeof(Tag);

	for (int i = 0; i < length; i++)
	{
		_TagList[tags[i]] = true;
	}
}

void TagCollection::Remove(Tag tags[])
{
	int length = sizeof(tags) / sizeof(Tag);

	for (int i = 0; i < length; i++)
	{
		_TagList[tags[i]] = false;
	}
}

bool TagCollection::Contains(Tag tag)
{
	return _TagList[tag];
}
