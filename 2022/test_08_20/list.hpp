#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>

namespace bite
{

    // 适配器 -- 复用
    
    // List的节点类

    template<class T>
    struct ListNode
    {

        ListNode(const T& val = T())
            :_val(val)
        {
            _pPre = nullptr;
            _pNext = nullptr;
        }

        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };


   /* template<class Iterator, class Ref, class Ptr>
    struct Reverse_iterator
    {
        Iterator _it;
        typedef Reverse_iterator<Iterator, Ref, Ptr> Self;

        Reverse_iterator(Iterator it)
            :_it(it)
        {}

        Ref operator*()
        {
            Iterator tmp = _it;
            return *(--tmp);
        }

        Ptr operator->()
        {
            return &(operator*());
        }

        Self& operator++()
        {
            --_it;
            return *this;
        }

        Self& operator--()
        {
            ++_it;
            return *this;
        }

        bool operator!=(const Self& s)
        {
            return _it != s._it;
        }
    };*/

    template<class Iterator>
    struct Reverse_iterator
    {
        Iterator _it;
        typedef Reverse_iterator<Iterator> Self;
        typedef typename Iterator::reference Ref;
        typedef  typename Iterator::pointer Ptr;

        Reverse_iterator(Iterator it)
            :_it(it)
        {}

        Ref operator*()
        {
            Iterator tmp = _it;
            return *(--tmp);
        }

        Ptr operator->()
        {
            return &(operator*());
        }

        Self& operator++()
        {
            --_it;
            return *this;
        }

        Self& operator--()
        {
            ++_it;
            return *this;
        }

        bool operator!=(const Self& s)
        {
            return _it != s._it;
        }
    };
    //List的迭代器类
    template<class T, class Ref, class Ptr>
    class ListIterator
    {
    
        typedef ListNode<T>* PNode;

        typedef ListIterator<T, Ref, Ptr> Self;
    public:
        typedef Ref reference;
        typedef Ptr pointer;

    public:

        ListIterator(PNode pNode = nullptr)
            :_pNode(pNode)
        {
        }

        ListIterator(const Self& l)
        {
            _pNode = l._pNode;
        }

        T& operator*()
        {
            return _pNode->_val;
        }

        T* operator->()
        {
            return &_pNode->_val;
        }

        Self& operator++()
        {
            _pNode = _pNode->_pNext;
            return *this;
        }

        Self operator++(int)
        {
            Self ret(*this);
            ++(*this);
            return ret;
        }

        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return *this;
        }
        

        Self& operator--(int)
        {
            Self ret(*this);
            --(*this);
            return ret;
        }

        bool operator!=(const Self& l)
        {
            return _pNode != l._pNode;
        }

        bool operator==(const Self& l)
        {
            return !(*this != l);
        }
    public:

        PNode _pNode; // 这是一个指针

    };



    //list类

    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;

    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T&> const_iterator;
        typedef  Reverse_iterator<iterator> reverse_iterator;
        typedef  Reverse_iterator<const_iterator> const_reverse_iterator;

       /* typedef  Reverse_iterator<iterator, T&, T*> reverse_iterator;
        typedef  Reverse_iterator<const_iterator, const T&, const T&> const_reverse_iterator;*/
    public:

        // List的构造

        list()
        {
            CreateHead();
        }

        list(int n, const T& value = T())
        {
            CreateHead();
            for (int i = 0; i < n; i++)
            {
                push_back(value);
            }
        }

        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            CreateHead();
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        list(const list<T>& l)
        {
            CreateHead();
            list<T> ret(l.begin(), l.end());
            swap(ret);
        }

        list<T>& operator=(const list<T> l)
        {
            swap(l);
            return *this;
        }

        ~list()
        {
            clear();
            delete _pHead;
        }
        iterator begin()
        {
            return iterator(_pHead->_pNext);
        }

        iterator end()
        {
            return iterator(_pHead);
        }

        reverse_iterator rbegin()
        {
            return iterator(end());
        }

        reverse_iterator rend()
        {
            return iterator(begin());
        }

        const_reverse_iterator rcbegin() const
        {
            return iterator(end());
        }

        const_reverse_iterator rcend() const
        {
            return iterator(begin());
        }
        const_iterator begin()const
        {
            return const_iterator(_pHead->_pNext);
        }

        const_iterator end()const 
        {
            return  const_iterator(_pHead);
        }

        size_t size()const
        {
            int count = 0;
            const_iterator it = begin();
            while (it != end())
            {
                it++;
                count++;
            }
            return count;
        }
        bool empty()const
        {
            return size() == 0;
        }


        T& front()
        {
            assert(!empty());
            return _pHead->_pNext->_val;
        }

        const T& front()const
        {
            assert(!empty());
            return _pHead->_pNext->_val;
        }

        T& back()
        {
            assert(!empty());
            return _pHead->_pPre->_val;
        }

        const T& back()const
        {
            assert(!empty());
            return _pHead->_pPre->_val;
        }


        void push_back(const T& val) 
        { 
            insert(end(), val);
        }

        void pop_back() 
        { 
            erase(--end()); 
        }

        void push_front(const T& val) 
        { 
            insert(begin(), val); 
        }

        void pop_front()
        { 
            erase(begin()); 
        }

        // 在pos位置前插入值为val的节点

        iterator insert(iterator pos, const T& val)
        {
            // 记录 迭代器 对应的 节点指针    
            Node* ppos = pos._pNode;
            Node* cur = new Node(val);

            // 记录 前一个 节点    
            Node* prev = ppos->_pPre;

            cur->_pNext = ppos;
            ppos->_pPre = cur;
            cur->_pPre = prev;
            prev->_pNext = cur;

            return cur;
        }

        iterator erase(iterator pos)
        {
            Node* ppos = pos._node;
            // 不能 删哨兵位                                                                     
            assert(pos != _pHead);
            Node* prev = ppos->_pPre;
            Node* next = ppos->_pNext;

            prev->_pNext = next;
            next->_pPre = prev;
            delete ppos;
            return iterator(next);
        }

        void clear()
        {
            PNode prev = _pHead;
            PNode next = prev->_pNext;
            while (next != _pHead)
            {
                prev = next;
                next = next->_pNext;
                delete prev;
            }
        }

        void swap(list<T>& l)
        {
            std::swap(_pHead, l._pHead);
        }

    private:
        

        void CreateHead()
        {
            _pHead = new Node;
            _pHead->_pNext = _pHead;
            _pHead->_pPre = _pHead;
        }

        PNode _pHead;

    };
};









////namespace bit
////{
////    ////  这个 是 list 节点
////    template<class T>
////    struct _list_node
////    {
////        _list_node<T>* _next;
////        _list_node<T>* _prev;
////        T _data;
////
////        // 先看看  构造函数 要不要写
////        _list_node(const T& t = T())
////            :_next(nullptr)
////            , _prev(nullptr)
////            , _data(t)
////        {
////        }
////    };
////
////
////    ////  迭代器
////    ////  T  T&  T*
////    //template<class T,class Ref,class Ptr>
////   
////    //struct _list_iterator
////    //{
////    //    typedef _list_node<T> Node;
////    //    typedef _list_iterator<T,Ref,Ptr> self;
////    //   
////    //    Node* _node;
////
////    //    _list_iterator(Node* node)
////    //        :_node(node)
////    //    {
////    //    }
////
////    //    // 析构  拷贝  都不需要
////
////    //    bool operator==(const self& t) const
////    //    {
////    //        return !(*this != t);
////    //    }
////
////    //    Ptr operator->()
////    //    {
////    //        return &_node->_data;
////    //    }
////
////    //    Ref operator*()
////    //    {
////    //        return _node->_data;
////    //    }
////
////
////    //    bool operator!=(const self& t) const
////    //    {
////    //        return _node != t._node;
////    //    }
////    //    //前置
////    //    self& operator++()
////    //    {
////    //        _node = _node->_next;
////    //        return *this;
////    //    }
////
////    //    self& operator--()
////    //    {
////    //        _node = _node->_prev;
////    //        return *this;
////    //    }
////    //    // 后置
////    //    self operator++(int)
////    //    {
////    //        self cur = *this;
////    //        _node = _node->_next;
////    //        return cur;
////    //    }
////
////    //    self operator--(int)
////    //    {
////    //        self cur(*this);
////    //        _node = _node->_prev;
////    //        return cur;
////    //    }
////
////    //};
////
////    //template<class T> //  这个 就是一个模板
////    //class list
////    //{
////    //public:
////    //    typedef _list_node<T> Node;
////    //  
////    //    typedef _list_iterator<T,T&,T*> iterator;
////    //    typedef _list_iterator<T,const T& ,const T*> const_iterator;
////    //    //  要有 构造函数  作为 一个  标记位
////
////    //    list()
////    //    {
////    //        // 首先 new 一个头节点
////    //        _head = new Node;
////    //        _head->_next = _head;
////    //        _head->_prev = _head;
////    //    }
////
////    // 
////    //    // 插入  不做说明的话 我们 插入 节点的前面
////    //    iterator insert(iterator pos, const T& val)
////    //    {
////    //        // 记录 迭代器 对应的 节点指针
////    //        Node* ppos = pos._node;
////    //        Node* cur = new Node(val);
////
////    //        // 记录 前一个 节点
////    //        Node* prev = ppos->_prev;
////
////    //        cur->_next = ppos;
////    //        ppos->_prev = cur;
////    //        cur->_prev = prev;
////    //        prev->_next = cur;
////
////    //        return iterator(cur);
////    //    }
////    //   
////    //    void push_back(const T& val)
////    //    {
////    //        insert(end(), val);
////    //    }
////
////    //
////
////    //    
////    //    // 迭代器
////    //    iterator begin()
////    //    {
////    //        return iterator(_head->_next);
////    //    }
////
////    //    const_iterator begin() const
////    //    {
////    //        return const_iterator(_head->_next);
////    //    }
////
////    //    const_iterator end() const
////    //    {
////    //        return const_iterator(_head);
////    //    }
////    //    iterator end()
////    //    {
////    //        return iterator(_head);
////    //    }
////
////    //private:
////
////    //    Node* _head;
////    //};
////template<class T>
////struct _list_iterator
////{
////    typedef _list_node<T> Node;
////
////    typedef _list_iterator<T> self;
////    Node* _node;
////
////    _list_iterator(Node* node)
////        :_node(node)
////    {
////    }
////
////    // 析构  拷贝  都不需要
////
////    bool operator==(const self& t) const
////    {
////        return !(*this != t);
////    }
////
////    T* operator->()
////    {
////        return &_node->_data;
////    }
////
////    T  operator*()
////    {
////        return _node->_data;
////    }
////
////
////    bool operator!=(const self& t) const
////    {
////        return _node != t._node;
////    }
////    //前置
////    self& operator++()
////    {
////        _node = _node->_next;
////        return *this;
////    }
////
////    self& operator--()
////    {
////        _node = _node->_prev;
////        return *this;
////    }
////    // 后置
////    self operator++(int)
////    {
////        self cur = *this;
////        _node = _node->_next;
////        return cur;
////    }
////
////    self operator--(int)
////    {
////        self cur(*this);
////        _node = _node->_prev;
////        return cur;
////    }
////
////};
////
////template<class T> //  这个 就是一个模板
////class list
////{
////public:
////    typedef _list_node<T> Node;
////    typedef _list_iterator<T> iterator;
////    typedef _list_iterator<const T> const_iterator;
////    // 迭代器
////          // 插入  不做说明的话 我们 插入 节点的前面
////        iterator insert(iterator pos, const T& val)
////        {
////            // 记录 迭代器 对应的 节点指针
////            Node* ppos = pos._node;
////            Node* cur = new Node(val);
////
////            // 记录 前一个 节点
////            Node* prev = ppos->_prev;
////
////            cur->_next = ppos;
////            ppos->_prev = cur;
////            cur->_prev = prev;
////            prev->_next = cur;
////
////            return iterator(cur);
////        }
////       
////        void push_back(const T& val)
////        {
////            insert(end(), val);
////        }
////    iterator begin()
////    {
////        return iterator(_head->_next);
////    }
////
////    const_iterator begin() const
////    {
////        return const_iterator(_head->_next);
////    }
////    private:
////
////       Node* _head;
////};
//
//#include <assert.h>
//namespace bit
//{
//    ////  这个 是 list 节点
//    template<class T>
//    struct _list_node
//    {
//        _list_node<T>* _next;
//        _list_node<T>* _prev;
//        T _data;
//
//        // 先看看  构造函数 要不要写
//        _list_node(const T& t = T())
//            :_next(nullptr)
//            , _prev(nullptr)
//            , _data(t)
//        {
//        }
//    };
//
//
//    //  迭代器
//    //  T  T&  T*
//   template<class T, class Ref, class Ptr>
//  
//    struct _list_iterator
//    {
//        typedef _list_node<T> Node;
//       typedef _list_iterator<T, Ref, Ptr> self;
//
//        Node* _node;
//
//        _list_iterator(Node* node)
//            :_node(node)
//        {
//        }
//
//        // 析构  拷贝  都不需要
//
//        bool operator==(const self& t) const
//        {
//            return !(*this != t);
//        }
//
//        Ptr operator->()
//        {
//            return &_node->_data;
//        }
//
//        Ref operator*()
//        {
//            return _node->_data;
//        }
//
//       
//        bool operator!=(const self& t) const
//        {
//            return _node != t._node;
//        }
//        //前置
//        self& operator++()
//        {
//            _node = _node->_next;
//            return *this;
//        }
//
//        self& operator--()
//        {
//            _node = _node->_prev;
//            return *this;
//        }
//        // 后置
//        self operator++(int)
//        {
//            self cur = *this;
//            _node = _node->_next;
//            return cur;
//        }
//
//        self operator--(int)
//        {
//            self cur(*this);
//            _node = _node->_prev;
//            return cur;
//        }
//
//    };
//
//    template<class T> //  这个 就是一个模板
//    class list
//    {
//    public:
//        typedef _list_node<T> Node;
//
//        typedef _list_iterator<T, T&, T*> iterator;
//       
//        typedef _list_iterator<T, const T&, const T*> const_iterator;
//        //  要有 构造函数  作为 一个  标记位
//
//        list()
//        {
//            // 首先 new 一个头节点
//            _head = new Node;
//            _head->_next = _head;
//            _head->_prev = _head;
//        }
//
//
//        // 插入  不做说明的话 我们 插入 节点的前面
//        iterator insert(iterator pos, const T& val)
//        {
//            // 记录 迭代器 对应的 节点指针
//            Node* ppos = pos._node;
//            Node* cur = new Node(val);
//
//            // 记录 前一个 节点
//            Node* prev = ppos->_prev;
//
//            cur->_next = ppos;
//            ppos->_prev = cur;
//            cur->_prev = prev;
//            prev->_next = cur;
//
//            return iterator(cur);
//        }
//
//        void push_back(const T& val)
//        {
//            insert(end(), val);
//        }
//        // 迭代器
//        iterator begin()
//        {
//            return iterator(_head->_next);
//        }
//
//        const_iterator begin() const
//        {
//            return const_iterator(_head->_next);
//        }
//
//        const_iterator end() const
//        {
//            return const_iterator(_head);
//        }
//        iterator end()
//        {
//            return iterator(_head);
//        }
//
//    private:
//
//        Node* _head;
//    };
//}