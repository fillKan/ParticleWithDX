#include "DXUT.h"
#include "ObjectManager.h"

void ObjectManager::Init()
{
}

void ObjectManager::Update()
{
    for (int tag = 0; tag < Tag::End; tag++) 
    {
        for (auto& iter = m_ObjectList[tag].begin(); iter != m_ObjectList[tag].end();) 
        {
            if ((*iter)->IsDestroyed) 
            {
                (*iter)->Release();
                delete *iter;

                iter = m_ObjectList[tag].erase(iter);
            }
            else
            {
                (*iter)->Update();

                CircleCollider* circle = (*iter)->GetComponent<CircleCollider>();
                if (circle != nullptr)
                {
                    CheckCollisionCircle(circle);
                }
                else
                {
                    BoxCollider* box = (*iter)->GetComponent<BoxCollider>();
                    if (box != nullptr) 
                    {
                        CheckCollisionBox(box);
                    }
                }
                iter++;
            }
        }
    }
}

void ObjectManager::Render()
{
    for (int tag = 0; tag < Tag::End; tag++)
    {
        for(auto& iter : m_ObjectList[tag])
        {
            iter->Render();
        }
    }
}

void ObjectManager::Release()
{
    ReleaseAllObject();
}

void ObjectManager::CheckCollisionCircle(CircleCollider* circle)
{
    Object* owner = circle->Owner;
    CircleCollider* otherCircle = nullptr;
    BoxCollider   * otherBox    = nullptr;

    for (int tag = 0; tag < Tag::End; tag++)
    {
        if (circle->Tags->Contains((Tag)tag))
        {
            for (auto& iter : m_ObjectList[tag])
            {
                otherCircle = iter->GetComponent<CircleCollider>();
                if (otherCircle != nullptr)
                {
                    if (circle->IsContactTo(*otherCircle))
                    {
                        owner->OnCollision(iter);
                        continue;
                    }
                }
                else
                {
                    otherBox = iter->GetComponent<BoxCollider>();
                    if (otherBox != nullptr)
                    {
                        if (circle->IsContactTo(*otherBox))
                        {
                            owner->OnCollision(iter);
                            continue;
                        }
                    }
                }
            }

        }
    }
}

void ObjectManager::CheckCollisionBox(BoxCollider* box)
{
    Object* owner = box->Owner;
    CircleCollider* otherCircle = nullptr;
    BoxCollider   * otherBox    = nullptr;

    for (int tag = 0; tag < Tag::End; tag++)
    {
        if (box->Tags->Contains((Tag)tag))
        {
            for (auto& iter : m_ObjectList[tag])
            {
                otherCircle = iter->GetComponent<CircleCollider>();
                if (otherCircle != nullptr)
                {
                    if (box->IsContactTo(*otherCircle))
                    {
                        owner->OnCollision(iter);
                        continue;
                    }
                }
                else
                {
                    otherBox = iter->GetComponent<BoxCollider>();
                    if (otherBox != nullptr)
                    {
                        if (box->IsContactTo(*otherBox))
                        {
                            owner->OnCollision(iter);
                            continue;
                        }
                    }
                }
            }
        }
    }
}

Object* ObjectManager::NewObject(string name, Vector2 position, Tag tag)
{
    Object* object = new Object();

    object->Init();
    object->Name = name;
    object->GetTransform()->Position = position;
    object->Tag = tag;

    m_ObjectList->push_back(object);

    return object;
}

void ObjectManager::ReleaseAllObject()
{
    for (int tag = 0; tag < Tag::End; tag++)
    {
        for (auto& iter : m_ObjectList[tag])
        {
            iter->Release();
            delete iter;
        }
        m_ObjectList[tag].clear();
    }
}
