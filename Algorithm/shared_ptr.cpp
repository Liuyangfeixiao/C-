
template<typename T>
class shared_ptr {
private:
    size_t* _count;
    T* _ptr;
public:
    shared_ptr(T* ptr = nullptr) : _ptr(ptr) {
        if (ptr) {
            _count = new size_t(1);
        }
        else {
            _count = new size_t(0);
        }
    }

    ~shared_ptr() {
        (*this->_count)--;
        if (*this->_count == 0) {
            delete this->_count;
            delete this->_ptr;
        }
    }

    shared_ptr(const shared_ptr& ptr) {
        if (this != ptr) {
            this->_ptr = ptr._ptr;
            this->_count = ptr._count;
            (*this->_count)++;
        }
    }

    shared_ptr& operator=(const shared_ptr& ptr) {
        if (this->_ptr == ptr._ptr)
            return *this;
        if (this->_ptr) {
            (*this->_count)--;
            if (*this->_count == 0) {
                delete this->_ptr;
                delete this->_count;
            }
        }
        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        (*this->_count)++;

        return *this;
    }

    T& operator*() {
        assert(this->_ptr == nullptr);
        return *(this->_ptr);
    }
    T* operator->() {
        assert(this->_ptr == nullptr);
        return this->_ptr;
    }

    size_t use_count() {
        return *(this->_count);
    }
};