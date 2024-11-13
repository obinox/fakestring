#include <stdexcept>
#ifndef FAKESTRING_H
#define FAKESTRING_H

#define INPUT_MAX 255
#define INPUT_MIN 0
#define EXP_MAX 10
#define EXP_MIN 0

template <typename T>
T pow(T b, int e);
class it
{
protected:
    char *p;

public:
    explicit it(char *q) : p(q) {}
    char &operator*() const { return *this->p; }
    it &operator++()
    {
        this->p++;
        return *this;
    }
    it operator++(int)
    {
        it t = *this;
        this->p++;
        return t;
    }
    bool operator==(const it &o) const { return p == o.p; }
    bool operator!=(const it &o) const { return p != o.p; }
    bool operator>(const it &o) const { return p > o.p; }
    bool operator>=(const it &o) const { return p >= o.p; }
    bool operator<(const it &o) const { return p < o.p; }
    bool operator<=(const it &o) const { return p <= o.p; }
};
class ri : public it
{
public:
    explicit ri(char *q) : it(q) {}
    ri &operator++()
    {
        this->p--;
        return *this;
    }
    ri operator++(int)
    {
        ri t = *this;
        this->p--;
        return t;
    }
};
class ci : public it
{
public:
    explicit ci(char *q) : it(q) {}
    const char &operator*() const { return *this->p; }
};
class cr : public ri
{
private:
    const char *c;

public:
    explicit cr(char *q) : ri(q) {}
    const char &operator*() const { return *this->p; }
};
class rf
{
private:
    char *p;

public:
    explicit rf(char *q) : p(q) {}

    char &operator*() const { return *p; }
};
class cf
{
private:
    const char *p;

public:
    explicit cf(const char *q) : p(q) {}

    const char &operator*() const { return *p; }
};
typedef unsigned long st;
typedef char *pt;
class charr
{
private:
    char *s;
    st l;
    st t;

public:
    static const st npos = -1;
    charr(const char *p = "")
    {
        this->l = 0;
        while (p[this->l] > 0)
            this->l++;
        this->s = new char[this->l + 1];
        st i;
        for (i = 0; i < this->l; i++)
        {
            this->s[i] = p[i];
        }
        this->s[i] = 0;
    }
    charr(const char *p, st n) : t(n)
    {
        this->s = new char[n + 1];
        st i;
        for (i = 0; i < n && p[i] > 0; i++)
        {
            this->s[i] = p[i];
        }
        this->l = i;
        this->s[i] = 0;
    }
    charr(const charr &p) : l(p.l), t(p.l)
    {
        this->s = new char[p.l + 1];
        st i;
        for (i = 0; i < this->l; i++)
        {
            this->s[i] = p.s[i];
        }
        this->s[i] = 0;
    }
    charr(const charr &p, st n) : t(n)
    {
        this->s = new char[n + 1];
        st i;
        for (i = 0; i < n && p.s[i] > 0; i++)
        {
            this->s[i] = p.s[i];
        }
        this->l = i;
        this->s[i] = 0;
    }
    charr(char c) : l(1), t(1)
    {
        this->s = new char[2];
        this->s[0] = c;
        this->s[1] = 0;
    }
    ~charr() { delete[] s; }

    const char *c_str() const { return this->s; }

    st length() const { return this->l; }
    st size() const { return this->t; }
    st resize()
    {
        *this = charr(*this);
        return this->t;
    }

    // st find_fc(char c, st n = 0) const {
    //     if (n >= this->l) {
    //         throw std::out_of_range("index out of range");
    //     }
    //     for (st i = 0; i < this->l; i++) {
    //         if (this->s[i] == c) {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    cf at(st o) const { return (*this)[o]; }
    rf at(st o) { return (*this)[o]; }

    cf front() const { return (*this)[0]; }
    rf front() { return (*this)[0]; }
    cf back() const { return (*this)[this->t - 1]; }
    rf back() { return (*this)[this->t - 1]; }

    const ci begin() const { return ci(this->s); }
    const ci cbegin() const { return ci(this->s); }
    it begin() { return it(this->s); }
    const ci end() const { return ci(this->s + this->t); }
    const ci cend() const { return ci(this->s + this->t); }
    it end() { return it(this->s + this->t); }
    const cr rbegin() const { return cr(this->s + this->t - 1); }
    const cr crbegin() const { return cr(this->s + this->t - 1); }
    ri rbegin() { return ri(this->s + this->t - 1); }
    const cr rend() const { return cr(this->s - 1); }
    const cr rend() const { return cr(this->s - 1); }
    ri rend() { return ri(this->s - 1); }

    void clear() { *this = ""; }
    bool empty() const { return this->l == 0; }

    int compare(const charr &p) const
    {
        st i = 0;
        while (i < this->l && i < p.l)
        {
            if (this->s[i] < p.s[i])
                return -1;
            if (this->s[i] > p.s[i])
                return 1;
            i++;
        }
        if (this->l < p.l)
            return -1;
        if (this->l > p.l)
            return 1;
        return 0;
    }
    int compare(st z, st n, const charr &p) const
    {
        if (z >= this->l)
        {
            throw std::out_of_range("position is out of range");
        }
        st i = 0;
        while (i + z < this->l && i < p.l && i < n)
        {
            if (this->s[i + z] < p.s[i])
                return -1;
            if (this->s[i + z] > p.s[i])
                return 1;
            i++;
        }
        if (this->l - n < p.l)
            return -1;
        if (this->l - n > p.l)
            return 1;
        return 0;
    }
    int compare(st z, st n, const charr &p, st o, st c) const
    {
        if (z >= this->l)
        {
            throw std::out_of_range("position is out of range");
        }
        if (o >= p.l)
        {
            throw std::out_of_range("offset is out of range");
        }
        st i = 0;
        while (i + z < this->l && i + o < p.l && i < n && i < c)
        {
            if (this->s[i + z] < p.s[i + o])
                return -1;
            if (this->s[i + z] > p.s[i + o])
                return 1;
            i++;
        }
        if (this->l - n < p.l - c)
            return -1;
        if (this->l - n > p.l - c)
            return 1;
        return 0;
    }
    int compare(const char *p) const
    {
        st q = 0;
        while (p[q] > 0)
            q++;
        st i = 0;
        while (i < this->l && i < q)
        {
            if (this->s[i] < p[i])
                return -1;
            if (this->s[i] > p[i])
                return 1;
            i++;
        }
        if (this->l < q)
            return -1;
        if (this->l > q)
            return 1;
        return 0;
    }
    int compare(st z, st n, const char *p) const
    {
        if (z >= this->l)
        {
            throw std::out_of_range("position is out of range");
        }
        st q = 0;
        while (p[q] > 0)
            q++;
        st i = 0;
        while (i + z < this->l && i < q && i < n)
        {
            if (this->s[i + z] < p[i])
                return -1;
            if (this->s[i + z] > p[i])
                return 1;
            i++;
        }
        if (this->l - n < q)
            return -1;
        if (this->l - n > q)
            return 1;
        return 0;
    }
    int compare(st z, st n, const char *p, st o) const
    {
        if (z >= this->l)
        {
            throw std::out_of_range("position is out of range");
        }
        st q = 0;
        while (p[q] > 0)
            q++;
        if (o >= q)
        {
            throw std::out_of_range("offset is out of range");
        }

        st i = 0;
        while (i + z < this->l && i + o < q && i < n)
        {
            if (this->s[i + z] < p[i + o])
                return -1;
            if (this->s[i + z] > p[i + o])
                return 1;
            i++;
        }
        if (this->l - n < q)
            return -1;
        if (this->l - n > q)
            return 1;
        return 0;
    }

    st copy(charr &p, st c, st o = 0) const
    {
        if (o >= this->l)
        {
            throw std::out_of_range("offset is out of range");
        }
        st y = (c + o > this->l) ? this->l - o : c;

        for (st i = 0; i < y; ++i)
        {
            p.s[i] = this->s[o + i];
        }

        return y;
    }

    it erase(it b, it e)
    {
        it p = b, q = e;
        if ((b < this->begin() || b > this->end()) || (e < this->begin() || e > this->end()) || (b > e))
        {
            throw std::out_of_range("iterator is out of range");
        }
        for (p = b, q = e; p != q; p++, q++)
        {
            *p = *q;
        }
        return it(&(*b) + 1);
    }
    charr &erase(st o = 0, st c = npos)
    {
        if (o + c >= this->l)
        {
            throw std::out_of_range("iterator is out of range");
        }
        st i;
        for (i = o; i < o + c; i++)
        {
            (*this)[i] = (*this)[i + c];
        }
        this->resize();
        return *this;
    }

    st find(char c, st o = 0) const
    {
        if (o >= this->l)
        {
            throw std::out_of_range("iterator is out of range");
        }
        st i;
        for (i = o; i < this->l; i++)
        {
            if (this->s[i] == c)
            {
                return i;
            }
        }
        return -1;
    }
    st find(const charr &p, st o = 0) const
    {
        if (o >= this->l)
        {
            throw std::out_of_range("iterator is out of range");
        }
        if (p.l == 0)
        {
            return o <= p.l ? o : -1;
        }
        st i;
        for (i = o; i < this->l; i++)
        {
            if (this->compare(i, p.l, p) == 0)
            {
                return i;
            }
        }
        return -1;
    }
    st find(const char *p, st o = 0) const
    {
        if (o >= this->l)
        {
            throw std::out_of_range("iterator is out of range");
        }
        st q = 0;
        while (p[q] > 0)
            q++;
        if (q == 0)
        {
            return o <= q ? o : -1;
        }
        st i;
        for (i = o; i < this->l; i++)
        {
            if (this->compare(i, q, p) == 0)
            {
                return i;
            }
        }
        return -1;
    }
    st find(const char *p, st o, st c) const
    {
        if (o >= this->l)
        {
            throw std::out_of_range("iterator is out of range");
        }
        st q = 0;
        while (p[q] > 0)
            q++;
        if (q == 0)
        {
            return o <= q ? o : -1;
        }
        st i;
        for (i = o; i < this->l && i < o + c; i++)
        {
            if (this->compare(i, q, p) == 0)
            {
                return i;
            }
        }
        return -1;
    }

    st rfind(char c, st o = npos) const
    {
        if (o >= this->l && o != npos)
        {
            throw std::out_of_range("iterator is out of range");
        }
        if (o == npos)
        {
            o = this->l;
        }
        st i;
        for (i = o - 1; i >= 0; i--)
        {
            if (this->s[i] == c)
            {
                return i;
            }
        }
        return -1;
    }
    st rfind(const charr &p, st o = npos) const
    {
        if (o >= this->l && o != npos)
        {
            throw std::out_of_range("iterator is out of range");
        }
        if (o == npos)
        {
            o = this->l;
        }
        if (p.l == 0)
        {
            return o <= p.l ? o : -1;
        }
        st i;
        for (i = o - 1; i >= 0; i--)
        {
            if (this->compare(i, p.l, p) == 0)
            {
                return i;
            }
        }
        return -1;
    }
    st rfind(const char *p, st o = npos) const
    {
        if (o >= this->l && o != npos)
        {
            throw std::out_of_range("iterator is out of range");
        }
        if (o == npos)
        {
            o = this->l;
        }
        st q = 0;
        while (p[q] > 0)
            q++;
        if (q == 0)
        {
            return o <= q ? o : -1;
        }
        st i;
        for (i = o - 1; i >= 0; i--)
        {
            if (this->compare(i, q, p) == 0)
            {
                return i;
            }
        }
        return -1;
    }
    st rfind(const char *p, st o, st c) const
    {
        if (o >= this->l && o != npos)
        {
            throw std::out_of_range("iterator is out of range");
        }
        if (o == npos)
        {
            o = this->l;
        }
        st q = 0;
        while (p[q] > 0)
            q++;
        if (q == 0)
        {
            return o <= q ? o : -1;
        }
        st i;
        for (i = o - 1; i >= 0 && i >= o - c; i--)
        {
            if (this->compare(i, q, p) == 0)
            {
                return i;
            }
        }
        return -1;
    }

    charr &insert(st z, st n, char c)
    {
        if (z >= this->l)
        {
            throw std::out_of_range("position is out of range");
        }
        char *r = new char[this->l + n + 1];
        st i = 0, j = 0;
        for (; j < z; i++, j++)
        {
            r[j] = this->s[i];
        }
        for (; j < z + n; j++)
        {
            r[j] = c;
        }
        for (; j < this->l + n; i++, j++)
        {
            r[j] = this->s[i];
        }
        r[j] = 0;
        this->l = this->l + n;
        this->t = this->l;

        delete[] this->s;
        this->s = r;
        return *this;
    }
    charr &insert(st z, const charr &p)
    {
        if (z >= this->l)
        {
            throw std::out_of_range("position is out of range");
        }
        char *r = new char[this->l + p.l + 1];
        st i = 0, j = 0;
        for (; j < z; i++, j++)
        {
            r[j] = this->s[i];
        }
        for (; j < z + p.l; j++)
        {
            r[j] = p.s[j - i];
        }
        for (; j < this->l + p.l; i++, j++)
        {
            r[j] = this->s[i];
        }
        r[j] = 0;
        this->l = this->l + p.l;
        this->t = this->l;

        delete[] this->s;
        this->s = r;
        return *this;
    }
    charr &insert(st z, const charr &p, st o, st c)
    {
        if (z >= this->l)
        {
            throw std::out_of_range("position is out of range");
        }
        if (o + c >= p.l)
        {
            throw std::out_of_range("offset is out of range");
        }
        char *r = new char[this->l + c + 1];
        st i = 0, j = 0;
        for (; j < z; i++, j++)
        {
            r[j] = this->s[i];
        }
        for (; j < z + c; j++)
        {
            r[j] = p.s[j - i + o];
        }
        for (; j < this->l + c; i++, j++)
        {
            r[j] = this->s[i];
        }
        r[j] = 0;
        this->l = this->l + c;
        this->t = this->l;

        delete[] this->s;
        this->s = r;
        return *this;
    }
    charr &insert(st z, const char *p)
    {
        if (z >= this->l)
        {
            throw std::out_of_range("position is out of range");
        }
        st q = 0;
        while (p[q] > 0)
            q++;
        char *r = new char[this->l + q + 1];
        st i = 0, j = 0;
        for (; j < z; i++, j++)
        {
            r[j] = this->s[i];
        }
        for (; j < z + q; j++)
        {
            r[j] = p[j - i];
        }
        for (; j < this->l + q; i++, j++)
        {
            r[j] = this->s[i];
        }
        r[j] = 0;
        this->l = this->l + q;
        this->t = this->l;

        delete[] this->s;
        this->s = r;
        return *this;
    }
    charr &insert(st z, const char *p, st c)
    {
        if (z >= this->l)
        {
            throw std::out_of_range("position is out of range");
        }
        st q = 0;
        while (p[q] > 0)
            q++;
        if (c >= q)
        {
            throw std::out_of_range("offset is out of range");
        }
        char *r = new char[this->l + c + 1];
        st i = 0, j = 0;
        for (; j < z; i++, j++)
        {
            r[j] = this->s[i];
        }
        for (; j < z + c; j++)
        {
            r[j] = p[j - i];
        }
        for (; j < this->l + c; i++, j++)
        {
            r[j] = this->s[i];
        }
        r[j] = 0;
        this->l = this->l + c;
        this->t = this->l;

        delete[] this->s;
        this->s = r;
        return *this;
    }

    charr &assign(char c)
    {
        *this = c;
        return *this;
    }
    charr &assign(const charr &p)
    {
        *this = p;
        return *this;
    }
    charr &assign(const char *p)
    {
        *this = p;
        return *this;
    }

    charr &append(st n, char c)
    {
        for (st i = 0; i < n; i++)
        {
            *this += c;
        }
        return *this;
    }
    charr &append(const charr &p)
    {
        *this += p;
        return *this;
    }
    charr &append(const charr &p, st o, st c)
    {
        *this += p;
        return *this;
    }
    charr &append(const char *p)
    {
        *this += p;
        return *this;
    }

    rf operator[](st o)
    {
        if (o >= this->l)
        {
            throw std::out_of_range("index out of range");
        }
        return rf(&this->s[o]);
    }
    cf operator[](st o) const
    {
        if (o >= this->l)
        {
            throw std::out_of_range("index out of range");
        }
        return cf(&this->s[o]);
    }
    charr &operator=(char c)
    {
        delete[] this->s;
        this->s = new char[2];
        this->s[0] = c;
        this->s[1] = 0;
        return *this;
    }
    charr &operator=(const charr &p)
    {
        if (this != &p)
        {
            return *this;
        }
        delete[] this->s;

        this->s = new char[p.l + 1];
        st i;
        for (i = 0; i < this->l; i++)
        {
            this->s[i] = p.s[i];
        }
        this->s[i] = 0;
        this->l = p.l;
        this->t = p.l;
        return *this;
    }
    charr &operator=(const char *p)
    {
        delete[] this->s;
        st q = 0;
        while (p[q] > 0)
            q++;
        this->s = new char[q + 1];
        st i;
        for (i = 0; i < q; i++)
        {
            this->s[i] = p[i];
        }
        this->s[i] = 0;
        this->l = q;
        this->t = this->l;
        return *this;
    }
    charr &operator+=(char c)
    {
        char *r = new char[this->l + 2];
        st i;
        for (i = 0; i < this->l; i++)
        {
            r[i] = this->s[i];
        }
        r[i] = c;
        i++;
        r[i] = 0;
        this->l += 1;
        this->t = this->l;

        delete[] this->s;
        this->s = r;
        return *this;
    }
    charr &operator+=(const charr &p)
    {
        char *r = new char[this->l + p.l + 1];
        st i;
        for (i = 0; i < this->l; i++)
        {
            r[i] = this->s[i];
        }
        for (; i < p.l; i++)
        {
            r[i] = p.s[i - this->l];
        }
        this->s[i] = 0;
        this->l = i;
        this->t = i;

        delete[] this->s;
        this->s = r;
        return *this;
    }
    charr &operator+=(const char *p)
    {
        delete[] this->s;

        st q = 0;
        while (p[q] > 0)
            q++;
        char *r = new char[this->l + q + 1];
        st i;
        for (i = 0; i < this->l; i++)
        {
            r[i] = this->s[i];
        }
        for (; i < q; i++)
        {
            r[i] = p[i - this->l];
        }
        this->s[i] = 0;
        this->l = i;
        this->t = i;

        delete[] this->s;
        this->s = r;
        return *this;
    }

    bool operator==(const charr &p) { return this->compare(p) == 0; }
    bool operator==(const char *p) { return this->compare(p) == 0; }
    bool operator!=(const charr &p) { return this->compare(p) != 0; }
    bool operator!=(const char *p) { return this->compare(p) != 0; }
    bool operator>(const charr &p) { return this->compare(p) > 0; }
    bool operator>(const char *p) { return this->compare(p) > 0; }
    bool operator>=(const charr &p) { return this->compare(p) >= 0; }
    bool operator>=(const char *p) { return this->compare(p) >= 0; }
    bool operator<(const charr &p) { return this->compare(p) < 0; }
    bool operator<(const char *p) { return this->compare(p) < 0; }
    bool operator<=(const charr &p) { return this->compare(p) <= 0; }
    bool operator<=(const char *p) { return this->compare(p) <= 0; }
};

#endif
