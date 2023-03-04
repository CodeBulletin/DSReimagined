#ifndef _DS_CONTAINER_H_
#define _DS_CONTAINER_H_

template<class T>
class Container {
protected:
    size_t m_size = 0;

public:
    virtual size_t getSize() {
        return m_size;
    }

    // virtual bool add(T obj) = 0;
    // virtual bool addAll() = 0;
    // virtual bool fill(T obj) = 0;
    // virtual T& max() = 0;
    // virtual T& min() = 0;
    // virtual bool sort() = 0;
    // virtual int remove() = 0;

};


#endif