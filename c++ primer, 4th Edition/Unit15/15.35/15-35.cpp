#include <iostream>
#include <string>
#include <set>

class Item_base
{
public:
	Item_base(double book_price = 0.0, std::string book_isbn = ""): price(book_price), isbn(book_isbn) {}
	std::string Book() const {return isbn;}
	virtual double NetPrice(const size_t count = 1) const {return price * count;}
	virtual Item_base* clone() const {return new Item_base(*this);}
	
protected:
	double price;

private:
	std::string isbn;
};

class DiscountBook : public Item_base
{
public:
	virtual double NetPrice(const size_t count = 2) const
	{
		if (count > min_num)
			return min_num * discount * price + (count - min_num) * price;
		else
			return min_num * discount * price;
	}
	virtual DiscountBook* clone() const {return new DiscountBook(*this);}

private:
	size_t min_num;
	double discount;
};

class Base_handle
{
public:
	Base_handle(): p(NULL), obj_count(new size_t(1)) {}
	explicit Base_handle(const Item_base &obj): p(obj.clone()), obj_count(new size_t(1)) {}
	Base_handle(const Base_handle &obj): p(obj.p), obj_count(obj.obj_count) {++*obj_count;}
	Base_handle& operator=(const Base_handle &pobj)
	{
		++*pobj.obj_count;
		delete_p();
		p = pobj.p;
		obj_count = pobj.obj_count;
		return *this;
	}
	Item_base operator*() const {return *p;}
	Item_base* operator->() const {return p;}
	~Base_handle() {delete_p();}

private:
	Item_base *p;
	size_t *obj_count;

	void delete_p()
	{
		if(--*obj_count == 0)
		{
			delete p;
			delete obj_count;
		}
	}
};

inline bool Compare(const Base_handle &obj1, const Base_handle &obj2)
{
	return obj1->Book() < obj2->Book();
}

class Basket
{
private:
	typedef bool (*comp) (const Base_handle&, const Base_handle&);

public:
	typedef std::multiset<Base_handle, comp>::size_type size_type;
	typedef std::multiset<Base_handle, comp>::iterator iterator;

	Basket()
		: item(Compare) { }

	void add_item(const Base_handle &obj)
	{
		item.insert(obj);
	}

	size_type size(const Base_handle &obj)
	{
		return item.count(obj);
	}

	double total() const
	{
		double sum = 0;
		for (iterator it = item.begin(); it != item.end(); it = item.upper_bound(*it))
		{
			sum += (*it)->NetPrice(item.count(*it));
		}
		return sum;
	}

private:
	std::multiset<Base_handle, comp> item;
};

int main(int argc, char const *argv[])
{
	
}
