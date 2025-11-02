
#include "core/os/os.h"
#include "core/config/engine.h"
#include <string>
#include "testMod.h"
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
const char * testMod::notifs_2_string(int id)
{   
    switch(id)
    {
        case NOTIFICATION_POSTINITIALIZE: return "NOTIFICATION_POSTINITIALIZE";
        case NOTIFICATION_PREDELETE: return "NOTIFICATION_PREDELETE";
        case NOTIFICATION_EXTENSION_RELOADED: return "NOTIFICATION_EXTENSION_RELOADED";
        case NOTIFICATION_PREDELETE_CLEANUP: return "NOTIFICATION_PREDELETE_CLEANUP";
        case NOTIFICATION_ENTER_TREE: return "NOTIFICATION_ENTER_TREE";
        case NOTIFICATION_EXIT_TREE: return "NOTIFICATION_EXIT_TREE";
        case NOTIFICATION_MOVED_IN_PARENT: return "NOTIFICATION_MOVED_IN_PARENT";
        case NOTIFICATION_READY: return "NOTIFICATION_READY";
        case NOTIFICATION_PAUSED: return "NOTIFICATION_PAUSED";
        case NOTIFICATION_UNPAUSED: return "NOTIFICATION_UNPAUSED";
        case NOTIFICATION_PHYSICS_PROCESS: return "NOTIFICATION_PHYSICS_PROCESS";
        case NOTIFICATION_PROCESS: return "NOTIFICATION_PROCESS";
        case NOTIFICATION_PARENTED: return "NOTIFICATION_PARENTED";
        case NOTIFICATION_UNPARENTED: return "NOTIFICATION_UNPARENTED";
        case NOTIFICATION_SCENE_INSTANTIATED: return "NOTIFICATION_SCENE_INSTANTIATED";
        case NOTIFICATION_DRAG_BEGIN: return "NOTIFICATION_DRAG_BEGIN";
        case NOTIFICATION_DRAG_END: return "NOTIFICATION_DRAG_END";
        case NOTIFICATION_PATH_RENAMED: return "NOTIFICATION_PATH_RENAMED";
        case NOTIFICATION_CHILD_ORDER_CHANGED: return "NOTIFICATION_CHILD_ORDER_CHANGED";
        case NOTIFICATION_INTERNAL_PROCESS: return "NOTIFICATION_INTERNAL_PROCESS";
        case NOTIFICATION_INTERNAL_PHYSICS_PROCESS: return "NOTIFICATION_INTERNAL_PHYSICS_PROCESS";
        case NOTIFICATION_POST_ENTER_TREE: return "NOTIFICATION_POST_ENTER_TREE";
        case NOTIFICATION_DISABLED: return "NOTIFICATION_DISABLED";
        case NOTIFICATION_ENABLED: return "NOTIFICATION_ENABLED";
        case NOTIFICATION_RESET_PHYSICS_INTERPOLATION: return "NOTIFICATION_RESET_PHYSICS_INTERPOLATION";
        case NOTIFICATION_ACCESSIBILITY_UPDATE: return "NOTIFICATION_ACCESSIBILITY_UPDATE";
        case NOTIFICATION_ACCESSIBILITY_INVALIDATE: return "NOTIFICATION_ACCESSIBILITY_INVALIDATE";
        case NOTIFICATION_WM_MOUSE_ENTER: return "NOTIFICATION_WM_MOUSE_ENTER";
        case NOTIFICATION_WM_MOUSE_EXIT: return "NOTIFICATION_WM_MOUSE_EXIT";
        case NOTIFICATION_WM_WINDOW_FOCUS_IN: return "NOTIFICATION_WM_WINDOW_FOCUS_IN";
        case NOTIFICATION_WM_WINDOW_FOCUS_OUT: return "NOTIFICATION_WM_WINDOW_FOCUS_OUT";
        case NOTIFICATION_WM_CLOSE_REQUEST: return "NOTIFICATION_WM_CLOSE_REQUEST";
        case NOTIFICATION_WM_GO_BACK_REQUEST: return "NOTIFICATION_WM_GO_BACK_REQUEST";
        case NOTIFICATION_WM_SIZE_CHANGED: return "NOTIFICATION_WM_SIZE_CHANGED";
        case NOTIFICATION_WM_DPI_CHANGE: return "NOTIFICATION_WM_DPI_CHANGE";
        case NOTIFICATION_VP_MOUSE_ENTER: return "NOTIFICATION_VP_MOUSE_ENTER";
        case NOTIFICATION_VP_MOUSE_EXIT: return "NOTIFICATION_VP_MOUSE_EXIT";
        case NOTIFICATION_WM_POSITION_CHANGED: return "NOTIFICATION_WM_POSITION_CHANGED";
        case NOTIFICATION_OS_MEMORY_WARNING: return "NOTIFICATION_OS_MEMORY_WARNING";
        case NOTIFICATION_TRANSLATION_CHANGED: return "NOTIFICATION_TRANSLATION_CHANGED";
        case NOTIFICATION_WM_ABOUT: return "NOTIFICATION_WM_ABOUT";
        case NOTIFICATION_CRASH: return "NOTIFICATION_CRASH";
        case NOTIFICATION_OS_IME_UPDATE: return "NOTIFICATION_OS_IME_UPDATE";
        case NOTIFICATION_APPLICATION_RESUMED: return "NOTIFICATION_APPLICATION_RESUMED";
        case NOTIFICATION_APPLICATION_PAUSED: return "NOTIFICATION_APPLICATION_PAUSED";
        case NOTIFICATION_APPLICATION_FOCUS_IN: return "NOTIFICATION_APPLICATION_FOCUS_IN";
        case NOTIFICATION_APPLICATION_FOCUS_OUT: return "NOTIFICATION_APPLICATION_FOCUS_OUT";
        case NOTIFICATION_TEXT_SERVER_CHANGED: return "NOTIFICATION_TEXT_SERVER_CHANGED";
        case NOTIFICATION_EDITOR_PRE_SAVE: return "NOTIFICATION_EDITOR_PRE_SAVE";
        case NOTIFICATION_EDITOR_POST_SAVE: return "NOTIFICATION_EDITOR_POST_SAVE";
        case NOTIFICATION_SUSPENDED: return "NOTIFICATION_SUSPENDED";
        case NOTIFICATION_UNSUSPENDED: return "NOTIFICATION_UNSUSPENDED";
        default: return "unsupported";
        }
        
}
void testMod::_process_setup_mode(double delta)
{
    //ERR_MAIN_THREAD_GUARD
    //ASSUMPTION IS IN EDITOR.

}
void testMod::_bind_methods() {
	// //MeshInstance3D::set_mesh();
    // //ClassDB::bind_method_custom
    // ClassDB::bind_method(D_METHOD("set_meshi", "mesh"), &treeGenNode::set_mesh);
    // ClassDB::bind_method(D_METHOD("get_meshi"), &treeGenNode::get_mesh);
    // //ClassDB::bind_method(D_METHOD("get_surface_override_material_count"), &MeshInstance3D::get_surface_override_material_count);
    // //ClassDB::bind_method(D_METHOD("set_surface_override_material", "surface", "material"), &MeshInstance3D::set_surface_override_material);
    // //ClassDB::bind_method(D_METHOD("get_surface_override_material", "surface"), &MeshInstance3D::get_surface_override_material);

    // //ClassDB::bind_method(D_METHOD("get_mesh"), &MeshInstance3D::get_mesh);
    // //ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "mesh", PROPERTY_HINT_RESOURCE_TYPE, "Mesh"), "set_mesh", "get_mesh");
    // //ClassDB::bind_method(D_METHOD("set_mesh", "mesh"), &MeshInstance3D::set_mesh);
    // //ClassDB::bind_method(D_METHOD("get_mesh"), &MeshInstance3D::get_mesh);
    // ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "mesh", PROPERTY_HINT_RESOURCE_TYPE, "Mesh"), "set_meshi", "get_meshi");
}

void testMod::_notification(int p_what)
{
    //turns out none of these fucking notifications are useful 
    // THEY FUCKING FIRE BEFORE THE THING IS VALID.
    if(NOTIFICATION_PROCESS != p_what)
        print_line(vformat("testMod %s %s|%s %d", my_name,get_name(), String(notifs_2_string(p_what)),p_what));
    switch(p_what)
    {
        case NOTIFICATION_ENTER_TREE:
        {

            //print_line(vformat("testMod entering tree %s %s", my_name,get_name()));
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
            //print_line(vformat("testMod entered the tree %s %s", my_name,get_name()));
        }
        break;
        case NOTIFICATION_READY:
        {
            auto tree =get_tree();
            if(Engine::get_singleton()->is_editor_hint())
                if(tree)
                {
                    add_child(&my_class_child);
                    my_class_child.set_owner(tree->get_edited_scene_root());
                }
                
            //if I have no children something is wrong.
            ///fuck this imma test something
            //oi = memnew(Node3D);
            //oi->set_name(String("fuck you"));
            //Engine::get_singleton()
            //get_parent()
            //get_owner
           

            
            //if (my_class_child.get_parent() == nullptr)
                
            //add_child(oi,false);
            //print_line(vformat("testMod Ready, %s %s", get_me_ptr(),get_name()));
        }
        break;
        case NOTIFICATION_EDITOR_PRE_SAVE:
        {
            //print_line("testMod saving, %s",get_me_ptr());
        }
        break;
        case NOTIFICATION_EDITOR_POST_SAVE:
        {
            //print_line("testMod Saved , %s",get_me_ptr());
        }
        break;
        case NOTIFICATION_SUSPENDED:
        {
            //print_line("testMod NOTIFICATION_SUSPENDED, %s",get_me_ptr());
        }
        break;
        case NOTIFICATION_UNSUSPENDED:
        {
            //print_line("testMod NOTIFICATION_UNSUSPENDED %s",get_me_ptr());
        }
        break;
        case NOTIFICATION_PROCESS:
        {
            process(get_tree()->get_process_time());
            //ah i know how to make this not depend on a mutex.
            //set_owner();
        }
        break;
        default:
            //print_line("unsupported event TestMod %d",p_what);
        break;

    };

}


String testMod::get_me_ptr()
{
    std::string tmp_name=std::to_string(reinterpret_cast<uintptr_t>(this));
	return String(tmp_name.c_str());
}

void testMod::process(float delta_time)
{
    // //literally only call when notified print_line(get_owner());
    //         print_line("whos the parent?");
    //         print_line(get_parent());
    //         if(Engine::get_singleton()->is_editor_hint())
    //         {
    //             //internal_child =memnew(Node3D);
    //             //internal_child->set_name("JESUS TAKE THE WHEEL");
    //             /*my_class_child.set_name(my_name);*/
    //             print_line(get_owner());
                
    //             my_class_child.set_owner(get_owner());
    //             //add_child(internal_child);
    //         }
    // if(Engine::get_singleton()->is_editor_hint())
    // {
    //     // i might just make two versions of this 
    //     set_owner()
    //     if(!my_class_child.get_parent())
    //     {
    //         add_child(&my_class_child,false, INTERNAL_MODE_FRONT);
    //     }
            
    // }
            
    // \
    // print_line("go to hell");

}

testMod::testMod():count(0),my_name(),my_class_child(),setup(false)
{
    const std::string tmp_name=std::to_string(reinterpret_cast<uintptr_t>(this));
    my_name = String(tmp_name.c_str());
    set_name("only youuuuuu");
    
    print_line(vformat("testMod %s, %s",my_name, get_name()));
    //Engine::get_singleton()
    //print_line("hi created treegennode %s",);
    //set_name("constructed");
    //my_mesh.set_name(get_name());
    const std::string tmp_o_name=std::to_string(reinterpret_cast<uintptr_t>(&my_class_child));
    if(my_class_child.get_parent()==nullptr)
    {
        print_line("child, %s, has appeared",String(tmp_o_name.c_str()));    
        //my_mesh.set_name();
        print_line(my_class_child.get_name());
    }
    else
    {
        print_line("child, %s, has appeared",String(tmp_o_name.c_str()));
    }
    set_process(true);
    set_process_mode(PROCESS_MODE_ALWAYS);
    //set_name()
    //my_mesh.set_name();
    //my_mesh.get_name
    //my_mesh.set_name(get_name()+String("_mesh"))
    //my_mesh.set_unique_name_in_owner
    //;
}

testMod::~testMod()
{
    print_line(vformat("Destructing %s.", my_name));

    //so the issue lies not in destruction?
}
