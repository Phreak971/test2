#include <iostream>
#include <tinyxml2.h>

int main() 
{
  tinyxml2::XMLDocument doc;

  tinyxml2::XMLElement* rootElement = doc.NewElement("geodetic_data");
  doc.InsertFirstChild(rootElement);

  tinyxml2::XMLElement* stationElement = doc.NewElement("station");
  stationElement->SetAttribute("name", "MyObservationPoint");
  stationElement->SetAttribute("id", "STA001");
  rootElement->InsertEndChild(stationElement);

  tinyxml2::XMLElement* latitudeElement = doc.NewElement("latitude");
  latitudeElement->InsertEndChild(doc.NewText("40.7544 N"));
  stationElement->InsertEndChild(latitudeElement);

  tinyxml2::XMLElement* longitudeElement = doc.NewElement("longitude");
  longitudeElement->InsertEndChild(doc.NewText("73.9856 W"));
  stationElement->InsertEndChild(longitudeElement);

  tinyxml2::XMLElement* elevationElement = doc.NewElement("elevation");
  elevationElement->InsertEndChild(doc.NewText("123.45 meters"));
  stationElement->InsertEndChild(elevationElement);

  tinyxml2::XMLElement* stationElement2 = doc.NewElement("station");
  stationElement2->SetAttribute("name", "Observation Point 2");
  stationElement2->SetAttribute("id", "STA002");
  rootElement->InsertEndChild(stationElement2);

  stationElement2->InsertEndChild(doc.NewElement("latitude"))->InsertEndChild(doc.NewText("37.8044 N"));
  stationElement2->InsertEndChild(doc.NewElement("longitude"))->InsertEndChild(doc.NewText("122.4194 W"));
  stationElement2->InsertEndChild(doc.NewElement("elevation"))->InsertEndChild(doc.NewText("567.89 meters"));

  // Save the document to a file
  if (doc.SaveFile("geodetic_data.xml") != tinyxml2::XMLError::XML_SUCCESS) {
    std::cerr << "Error saving XML file!" << std::endl;
    return 1;
  }

  std::cout << "Geodetic data written to 'geodetic_data.xml'" << std::endl;
  return 0;
}
