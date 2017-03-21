#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;

class XMLBuilder;

struct XMLElement
{
	string name;
	string value;
	vector<XMLElement> elements;
	const size_t indent_size = 2;

	XMLElement() {};

	XMLElement(const string& name, const string& value)
		: name{ name },
		value{ value }
	{
	}

	string str(int indent = 0) const
	{
		ostringstream oss;
		string i(indent_size * indent, ' ');
		oss << i << "<" << name << ">" << endl;

		if (value.size() > 0)
			oss << string(indent_size * (indent + 1), ' ') << value << endl;

		for (const auto& e : elements)
			oss << e.str(indent + 1);

		oss << i << "</" << name << ">" << endl;

		return oss.str();
	}

	static XMLBuilder build(string root_name);
	static unique_ptr<XMLBuilder> create(string root_name);
};

struct XMLBuilder
{

	XMLBuilder(string root_name)
	{
		root.name = root_name;
	}

	XMLBuilder& add_child(string child_name, string child_value)
	{
		XMLElement e{ child_name,child_value };
		root.elements.emplace_back(e);
		return *this;
	}

	XMLBuilder* add_child_ptr(string child_name, string child_value)
	{
		XMLElement e{ child_name,child_value };
		root.elements.emplace_back(e);
		return this;
	}

	operator XMLElement() const { return root; };

	string str() { return root.str(); }

	XMLElement root;
};

XMLBuilder XMLElement::build(string root_name)
{
	return XMLBuilder(root_name);
}

unique_ptr<XMLBuilder> XMLElement::create(string root_name)
{
	return make_unique<XMLBuilder>(root_name);
}


int main()
{
	XMLBuilder builder{ "Book" };
	builder.add_child("Reference", "X001");
	builder.add_child("Title", "Women");
	cout << builder.str() << endl;
	/*
	<Book>
	  <Reference>
	    X001
	  </Reference>
	  <Title>
	    Women
	  </Title>
	</Book>
	*/

	XMLElement e = XMLElement::build("Book").
		add_child("Reference", "X001").
		add_child("Title", "Women");
	cout << e.str() << endl;


	XMLElement xml = *XMLElement::create("Person")->add_child_ptr("Name", "machaaouri")->add_child_ptr("Age", "27");
	cout << xml.str() << endl;

	getchar();
	return 0;
}
