#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

void PrintElementWithIndentation(XMLElement *element, int indentLevel)
{
    string indent(indentLevel * 2, ' ');

    cout << indent << element->Value();
    for (const XMLAttribute *attribute = element->FirstAttribute(); attribute; attribute = attribute->Next())
    {
        cout << " " << attribute->Name() << "=\"" << attribute->Value() << "\"";
    }

    // Check for text content
    if (element->GetText())
    {
        cout << ": " << element->GetText() << endl;
    }
    else
    {
        cout << endl;
    }

    // Recursively print child elements
    for (XMLElement *child = element->FirstChildElement(); child; child = child->NextSiblingElement())
    {
        PrintElementWithIndentation(child, indentLevel + 1);
    }
}

int main()
{
    // Define the path to your XML file
    string filename = "dream.xml";

    // Open the XML file
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    // Create a TinyXML2 document
    XMLDocument doc;
    string xmlString((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    doc.Parse(xmlString.c_str());
    file.close(); // Close the file after loading

    if (doc.Error())
    {
        cerr << "Error parsing XML file: " << doc.ErrorStr() << endl;
        return 1;
    }

    // Get the root element
    XMLElement *root = doc.RootElement();
    if (root)
    {
        cout << "** XML Document **" << endl;
        PrintElementWithIndentation(root, 1);
    }
    else
    {
        cerr << "Error: No root element found in XML document." << endl;
    }

    return 0;
}
