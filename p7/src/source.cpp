#include <iostream>

#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>

using namespace std;
void getData( rapidxml::xml_node<char> *f, string st, bool ff)
{
    cout << f << endl;
    cout << st << endl;
    cout << ff << endl;
}

int main(int argc, char *argv[])
{
  try {
    namespace rx = rapidxml;
    // Read graph properties manually:
    rx::file<> file("data/sample.xml"); // (default template is char)
    rx::xml_document<> doc;
    doc.parse<0>(file.data());

    rx::xml_node<> *n_graphml = doc.first_node("graphml"); // root tag of the document
    if (n_graphml) {
      for (rx::xml_node<> *n = n_graphml->first_node("key"); n; n = n->next_sibling("key")) {
        rx::xml_attribute<> *intent = n->first_attribute("for");
        if (!intent || !intent->value()) {
          continue;
        }
        // Get an attribute from <key> tag:
        rx::xml_attribute<> *id = n->first_attribute("id"); 

        // If everything is valid, try to extract the data:
        string data;
        getData(n->first_node("default"), data, false);
        // ...
      }
    }
  } catch (exception &e) {
    cerr << e.what() << endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}