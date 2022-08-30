#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <assert.h>
#include <string.h>


//  vector �ĵײ�ģ��ʵ��   
//  ��������ʧЧ

namespace bit
{
	template<class T>
	class Vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		Vector()
      :_start(nullptr)
       ,_finish(nullptr)
       ,_endOfStoage(nullptr)
    {
    }


    void swap(Vector<T>& v)
    {
      std::swap(_start, v._start);
      std::swap(_finish, v._finish);
      std::swap(_endOfStoage, v._endOfStoage);
    }

    Vector(int n, const T& value = T())
      :_start(nullptr)
       ,_finish(nullptr)
       ,_endOfStoage(nullptr)
    {
      Vector<T> vv;
      for(int i=0;i<n;i++)
      {
        vv.push_back(value);
      }
      swap(vv);
    }

    ~Vector()
    {
      if(_start)
      {
        delete[] _start;
        _finish = nullptr;
        _endOfStoage = nullptr;
      }
    }

    template<class InputIterator>
    Vector(InputIterator first, InputIterator last)
      :_start(nullptr)
       ,_endOfStoage(nullptr)
       ,_finish(nullptr)
    {
      Vector<T> vv;
      while(first != last)
      {
        vv.push_back(*first);
        first++;
      }
      swap(vv);
    }

    //��������   ���
  
    Vector(const Vector<T>& v)
      :_start(nullptr)
       ,_finish(nullptr)
       ,_endOfStoage(nullptr)
    {
      // �ִ�д��
      Vector<T> vv(v.begin(),v.end());
      swap(vv);
    }

    Vector<T>& operator=(Vector<T> v)
    {
      // ����ԭ���� �����ڴ�й©
      swap(v);
      return *this;
    }



    // ���㳤��
		size_t size() const 
    {
      return _finish - _start;
    }
  
    //  ���� ����
  
    size_t capacity() const 
    {
      return _endOfStoage - _start;
    }
                                //  �ϸ� �ı����� ���ܲ���  ��������Ҳ�й��캯��
    void resize(size_t n,const T& val = T())
    {
      // ���� ���
      reserve(n);

      if(n > size())
      {
        while(size() < n)
        {
          // 
          *_finish = val;
          _finish++;
        }
      }
      else 
      {
        _finish = _start + n;
      }

    }

    iterator erase(iterator pos)
    {
      assert(pos >= _start && pos < _finish);
      iterator it = pos + 1;
      while(it != _finish)
      {
        *(it-1) = *it;
        it++;
      }
      _finish--;
      return pos;
    }

    iterator insert(iterator pos, const T& x)
    {
        assert(pos >= _start && pos <= _finish);
        if(_finish == _endOfStoage)
        {
          size_t len = pos - _start; // ��¼ ��ֹʧЧ
          size_t newCap = _endOfStoage - _start == 0 ? 4 : 2 * capacity();
          reserve(newCap);
          // ���� pos 
          pos = _start + len;
        }
        //  ��ʼ  ��������
        iterator it = _finish;
        while(it != pos)
        {
          *it = *(it - 1);
          it--;
        }
        *pos = x;
        _finish++;
        return pos;
    }


    void reserve(size_t n = 0)
    {
      size_t oldsize = size();
    
      if(n > capacity())
      {
        // ��һ��ռ�
        T* tmp = new T[n];
        // �ж�  �Ϳռ���û�� ����
        if(_start)
        {
          // ����ֱ�� ��ֵ  ���� �Զ������� ���Զ����
          for(int i=0;i<size();i++)
          {
            tmp[i] = _start[i];
          }

          // memcpy(tmp,_start,size()*sizeof(T));
          delete[] _start;
        }

        _start = tmp;
        _finish = tmp + oldsize;
        _endOfStoage = tmp + n;
      }

    }

    void pop_back()
    {
      if(size() != 0)   //  ���� ��ò�Ҫ�� �����ж�  ����clear
      {
        --_finish;
      }
    }

    T& operator[](size_t pos)
    {
      assert(pos >= 0 && pos < size());
      return *(_start+pos);
    }
    const T& operator[](size_t pos) const
    {
      assert(pos >= 0 && pos < size());
      return *(_start+pos);
    }

    // β�� ���� ����  insert
    void push_back(const T& val)
    {


      insert(_finish,val);


      //  ���  ���� 
      /*if(_finish == _endOfStoage)
      {
        size_t newCap = _endOfStoage - _start == 0 ? 4 : 2 * capacity();
        reserve(newCap);
      }

      // ������
      *_finish = val;
      _finish++;
      */
    }
    
    void clear()
    {
      _finish = _start;
    }

    // ������

    //  ������
    iterator begin()
    {
      return _start;
    }

    const_iterator begin() const
    {
      return _start;
    }

    iterator end()
    {
      return _finish;
    }

    const_iterator end() const
    {
      return _finish;
    }


  private:
		iterator _start;
		iterator _finish;
		iterator _endOfStoage;
	};
}
