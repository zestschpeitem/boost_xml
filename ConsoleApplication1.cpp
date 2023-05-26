#include <boost/property_tree/ptree.hpp>                                                    
#include <boost/property_tree/xml_parser.hpp>                                               
#include <boost/property_tree/detail/file_parser_error.hpp>                                 
#include <iostream>                                                                         

namespace pt = boost::property_tree;


int main()
{                                            
    pt::ptree id_type_tree;

    try {
        read_xml("2.1.xml", id_type_tree);
    }
    catch (pt::xml_parser_error& e) {
        std::cout << "Failed to parse the xml string." << e.what();
    }
    catch (...) {
        std::cout << "Failed !!!";
    }

    for (auto& m : id_type_tree.get_child("videoSource")) {
        for (auto& p : m.second) {
            if (p.first == "id")
            {
                std::cout << "id:" << " " << p.second.data() << "" << std::endl;
            }
        }
    }

    for (auto& m : id_type_tree.get_child("videoSource")) {
        for (auto& p : m.second) {
            for (auto& c : p.second) {
                if (c.first == "id")
                {
                    std::cout << "id:" << " " << c.second.data() << "" << std::endl;
                }
                if (c.first == "xsi:type") {
                    std::cout << "xsi:type:" << " " << c.second.data() << "" << std::endl;
                }
            }
        }
        std::cout << "\n";
    }
    return 0;
}
