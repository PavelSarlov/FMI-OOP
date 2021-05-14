#include <cstring>
#include "JSONObject.h"

template <class T>
class JSONArray : public JSON<T>
{
private:
    JSON<T>** array;
    int size;
    int capacity;

    void resize();
public:
    JSONArray();
    JSONArray(const JSONArray& from);

    JSONArray& operator= (const JSONArray& from);

    ~JSONArray();

    JSON<T>* operator[] (const int& pos) const;
    void insert(const char* key, T value);
    void insert(const JSON<T>* obj);
    void remove(unsigned int index);
    bool remove(const char* key);

    T get_value(const char* key) const;

    int get_size() const;
};
template <class T>
void JSONArray<T>::resize()
{
    this->capacity *= 2;
    JSON<T>** new_array = new JSON<T>*[this->capacity];

    for (int i = 0; i < this->size; i++)
    {
        new_array[i] = this->array[i];
    }
    delete[] this->array;
    this->array = new_array;
}
template <class T>
JSONArray<T>::JSONArray()
{
    this->array = new JSON<T>*[1];
    this->array[0] = new JSON<T>();
    this->size = 0;
    this->capacity = 1;
}

template <class T>
JSONArray<T>::JSONArray(const JSONArray& from)
{
    this->array = new JSON<T>*[from.capacity];
    for (int i = 0; i < from.capacity; i++)
    {
        this->array[i] = new JSON<T>();
    }
    this->size = from.size;
    this->capacity = from.capacity;

    for (int i = 0; i < this->size; i++)
    {
        this->insert(from.array[i]);
    }
}

template <class T>
JSONArray<T>& JSONArray<T>::operator=(const JSONArray& from)
{
    if (this != &from)
    {
        for (int i = 0; i < this->size; i++)
        {
            delete this->array[i];
        }
        delete[] this->array;

        this->array = new JSON<T> * [from.capacity];
        for (int i = 0; i < from.capacity; i++)
        {
            this->array[i] = new JSON<T>();
        }
        this->size = from.size;
        this->capacity = from.capacity;

        for (int i = 0; i < this->size; i++)
        {
            this->insert(from.array[i]);
        }
    }
    return *this;
}

template <class T>
JSONArray<T>::~JSONArray<T>()
{
    for (int i = 0; i < this->size; i++)
    {
        delete this->array[i];
    }
    delete[] this->array;
}

template <class T>
JSON<T>* JSONArray<T>::operator[] (const int& pos) const
{
    return this->array[pos];
}

template <class T>
void JSONArray<T>::insert(const char* key, T value)
{
    if (this->size == this->capacity)
    {
        this->resize();
    }
    JSONObject<T>* temp = new JSONObject<T>();
    temp->set_key(key);
    temp->set_value(value);

    this->array[this->size] = temp;
    this->size++;
}

template <class T>
void JSONArray<T>::insert(const JSON<T>* obj)
{
    if (obj != nullptr)
    {
        try
        {
            this->insert(obj->get_key(), obj->get_value());
        }
        catch (int a)
        {
            if (this->size == this->capacity)
            {
                this->resize();
            }
            this->array[this->size] = new JSONArray(*(dynamic_cast<const JSONArray<T>*>(obj)));
            this->size += 1;
        }
    }
}

template <class T>
void JSONArray<T>::remove(unsigned int index)
{
    if (index<0 || index>this->size)
    {
        return;
    }

    JSON<T>** temp = new JSON<T> * [this->capacity];
    for (int i = 0, j = 0; i < this->size; i++)
    {
        if (i != index)
        {
            temp[j++] = this->array[i];
        }
        else
        {
            delete this->array[i];
        }
    }
    delete[] this->array;
    this->array = temp;
    this->size -= 1;
}

template <class T>
bool JSONArray<T>::remove(const char* key)
{
    for (int i = 0; i < this->size; i++)
    {
        try
        {
            if (strcmp(key, this->array[i]->get_key()) == 0)
            {
                JSON<T>** temp = new JSON<T> * [this->capacity];
                for (int j = 0, k = 0; j < this->size; j++)
                {
                    if (j != i)
                    {
                        temp[k++] = this->array[j];
                    }
                    else
                    {
                        delete this->array[j];
                    }
                }
                delete[] this->array;
                this->array = temp;
                this->size -= 1;
                return true;
            }
        }
        catch (int a) {}
    }
    for (int i = 0; i < this->size; i++)
    {
        try
        {
            if (this->array[i]->remove(key))
            {
                return true;
            }
        }
        catch (int a) {}
    }
}

template <class T>
T JSONArray<T>::get_value(const char* key) const
{
    for (int i = 0; i < this->size; i++)
    {
        try
        {
            if (strcmp(key, this->array[i]->get_key()) == 0)
            {
                return this->array[i]->get_value();
            }
        }
        catch (int a) {}
    }
    for (int i = 0; i < this->size; i++)
    {
        try
        {
            return this->array[i]->get_value(key);
        }
        catch (int a) {}
    }
    throw "key not found"; // Exception ?
}

template <class T>
int JSONArray<T>::get_size() const
{
    return this->size;
}
