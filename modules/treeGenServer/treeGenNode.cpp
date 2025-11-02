#include "treeGenNode.h"
#include "treeGenServer.h"
#include "treeGenServerServerInteractions.h"
#include "core/os/os.h"
#include <string>
void treeGenNode::set_mesh(const Ref<Mesh> &p_mesh)
{
    my_mesh.set_mesh(p_mesh);
}
Ref<Mesh> treeGenNode::get_mesh() const {
	return my_mesh.get_mesh();
}
// void treeGenNode::_get_property_list(List<PropertyInfo> *p_list) const
// {
//     //print_line(p_list->size());
//     /*
//     void MeshInstance3D::_get_property_list(List<PropertyInfo> *p_list) const {
// 	for (uint32_t i = 0; i < blend_shape_tracks.size(); i++) {
// 		p_list->push_back(PropertyInfo(Variant::FLOAT, vformat("blend_shapes/%s", String(mesh->get_blend_shape_name(i))), PROPERTY_HINT_RANGE, "-1,1,0.00001"));
// 	}
// 	if (mesh.is_valid()) {
// 		for (int i = 0; i < mesh->get_surface_count(); i++) {
// 			p_list->push_back(PropertyInfo(Variant::OBJECT, vformat("%s/%d", PNAME("surface_material_override"), i), PROPERTY_HINT_RESOURCE_TYPE, "BaseMaterial3D,ShaderMaterial", PROPERTY_USAGE_DEFAULT));
// 		}
// 	}
// }

//     */
//     //aaaaaaaaaaj
    
// }
void treeGenNode::_bind_methods()
{

    //MeshInstance3D::set_mesh();
    //ClassDB::bind_method_custom
    ClassDB::bind_method(D_METHOD("set_meshi", "mesh"), &treeGenNode::set_mesh);
    ClassDB::bind_method(D_METHOD("get_meshi"), &treeGenNode::get_mesh);
    //ClassDB::bind_method(D_METHOD("get_surface_override_material_count"), &MeshInstance3D::get_surface_override_material_count);
    //ClassDB::bind_method(D_METHOD("set_surface_override_material", "surface", "material"), &MeshInstance3D::set_surface_override_material);
    //ClassDB::bind_method(D_METHOD("get_surface_override_material", "surface"), &MeshInstance3D::get_surface_override_material);

    //ClassDB::bind_method(D_METHOD("get_mesh"), &MeshInstance3D::get_mesh);
    //ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "mesh", PROPERTY_HINT_RESOURCE_TYPE, "Mesh"), "set_mesh", "get_mesh");
    //ClassDB::bind_method(D_METHOD("set_mesh", "mesh"), &MeshInstance3D::set_mesh);
    //ClassDB::bind_method(D_METHOD("get_mesh"), &MeshInstance3D::get_mesh);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "mesh", PROPERTY_HINT_RESOURCE_TYPE, "Mesh"), "set_meshi", "get_meshi");
}

void treeGenNode::_notification(int p_what)
{
    //check for ready, before moving the child
    //the issue is figuring how it closes.
    switch(p_what)
    {
        case NOTIFICATION_ENTER_TREE:
        {

            //
            //[come back] print_line(vformat("Hi I am entering the tree %s %s", my_name,get_name()));
            ++count;
            if(count == 1)
            {
                //reparent it else remake it?
                //lets see if this works
                //add_child(&my_mesh,false);
            }
            //this fires whenever reparented too wth
        }
        break;
        case NOTIFICATION_POST_ENTER_TREE:
        {
            //[come back] print_line(vformat("Hi I have entered the tree %s %s", my_name,get_name()));
        }
        break;
        case NOTIFICATION_READY:
        {
            //[come back] print_line(vformat("Ready, %s %s", get_me_ptr(),get_name()));
        }
        break;
        case NOTIFICATION_EDITOR_PRE_SAVE:
        {
            //[come back] print_line("hi i am saving");
        }
        break;
        case NOTIFICATION_EDITOR_POST_SAVE:
        {
            //[come back] print_line("hi i have saving");
        }
        break;
        case NOTIFICATION_SUSPENDED:
        {
            //[come back] print_line("hi NOTIFICATION_SUSPENDED");
        }
        break;
        case NOTIFICATION_UNSUSPENDED:
        {
            //[come back] print_line("hi i have NOTIFICATION_UNSUSPENDED");
        }
        break;
        default:

        break;

    };

}

void treeGenNode::_mesh_changed()
{
    //[come back] print_line("hey there");
}

String treeGenNode::get_me_ptr()
{
    std::string tmp_name=std::to_string(reinterpret_cast<uintptr_t>(this));
	return String(tmp_name.c_str());
}

treeGenNode::treeGenNode():count(0),my_mesh(),my_name()
{
    std::string tmp_name=std::to_string(reinterpret_cast<uintptr_t>(this));
    my_name = String(tmp_name.c_str());
    //[come back] print_line(my_name);
    //[come back] print_line(vformat("My name is %s.", get_name()));
    //
    print_line("hi created treegennode %s",my_name);
    //set_name("constructed");
    //my_mesh.set_name(get_name());
    if(my_mesh.get_parent()==nullptr)
    {
        //[come back] print_line("yeah check this?");
        //my_mesh.set_name();
        //[come back] print_line(my_mesh.get_name());
    }
    //set_name()
    //my_mesh.set_name();
    //my_mesh.get_name
    //my_mesh.set_name(get_name()+String("_mesh"))
    //my_mesh.set_unique_name_in_owner
    //;
}

treeGenNode::~treeGenNode()
{
    //[come back] print_line(vformat("Destructing %s.", my_name));
    //so the issue lies not in destruction?
}
