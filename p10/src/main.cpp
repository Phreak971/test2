#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::property_tree;

void displayNode(const ptree& node, int indent = 0) {
  string indentation(indent * 2, ' ');

  switch (node.empty()) {
    case false:
      if (node.data().empty()) {
        cout << indentation << node.name() << endl;
        for (const auto& child : node) {
          displayNode(child, indent + 1);
        }
      } else {
        cout << indentation << node.name() << ": " << node.data() << endl;
      }
      break;
    default:
      cout << indentation << "<" << node.name() << " />" << endl;
  }
}

int main() {
  ptree tree;
  try {
    read_xml("dream.xml", tree); // Replace with your actual filename
  } catch (const exception& e) {
    cerr << "Error reading XML file: " << e.what() << endl;
    return 1;
  }

  cout << tree.get<string>("PLAY.TITLE") << endl;
  cout << endl;

  for (const auto& child : tree.get_child("PLAY")) {
    if (child.name() == "FM" || child.name() == "SCNDESCR" || child.name() == "PLAYSUBT") {
      cout << child.data() << endl << endl;
    } else if (child.name() == "PERSONAE") {
      displayNode(child);
      cout << endl;
    } else if (child.name() == "ACT") {
      displayNode(child);
      cout << endl;
    }
  }

  return 0;
}
