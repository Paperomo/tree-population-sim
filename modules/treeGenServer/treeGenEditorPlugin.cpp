#include "treeGenEditorPlugin.h"
#include "editor/editor_interface.h"
#include "editor/editor_data.h"
#include "scene/gui/check_box.h"
#include "treeGenNode.h"
void treeGenEditorPlugin::_bind_methods() {
}

void treeGenEditorPlugin::_notification(int p_what) {
	switch(p_what)
    {
        case NOTIFICATION_ENTER_TREE:
            //so this gets attached to the editor... why not just run the singleton here then lol
            ++count;
            print_line("oohweeooyh");
            if(count == 1)
            {
                if(!test_control)
                    test_control = memnew(CheckBox);
                add_control_to_container(CONTAINER_SPATIAL_EDITOR_SIDE_LEFT,test_control);
                test_control->set_visible(false);
                /*
                menu_button->set_text(ZN_TTR("Terrain"));
	menu_button->get_popup()->connect(
			"id_pressed", callable_mp(this, &VoxelTerrainEditorPlugin::_on_menu_item_selected)
	);
	menu_button->hide();
	add_control_to_container(CONTAINER_SPATIAL_EDITOR_MENU, menu_button);
                
                */
                //reparent it else remake it?
                //well lets just leave this as its for now
                
            }
            //this fires whenever reparented too wth
        break;
        default:

        break;

    };
}

void treeGenEditorPlugin::_editor_has_selected()
{
    if(selectionHandle->get_selected_nodes().size() == 1)
    {
        treeGenNode* tmp = Object::cast_to<treeGenNode>(selectionHandle->get_full_selected_node_list().get(0));
        if(tmp)
        {
            test_control->set_visible(true);
            return;
        }
    }
    if(test_control->is_visible())
        test_control->set_visible(false);
    //print_line();
}

void treeGenEditorPlugin::edit(Object *p_object) {
	treeGenNode* tmp = Object::cast_to<treeGenNode>(p_object);
        if(selectionHandle->is_selected(Object::cast_to<Node>(p_object)))
        {
            if(tmp) print_line("edited");
            else print_line("un_edited?");
        }
    //check until unselected?
}

bool treeGenEditorPlugin::handles(Object *p_object) const
{
    treeGenNode* tmp = Object::cast_to<treeGenNode>(p_object);
    if(tmp)
    {
        return true;
    }
    //i guess i could just catch all events.
    return false;
}

bool treeGenEditorPlugin::forward_canvas_gui_input(const Ref<InputEvent> &p_event) {
    //testing
    //print_line("detected");
    return true;
}

EditorPlugin::AfterGUIInput treeGenEditorPlugin::forward_3d_gui_input(Camera3D *p_camera, const Ref<InputEvent> &p_event) {
//
    
    //print_line(p_event->get_type());
    return EditorPlugin::AfterGUIInput::AFTER_GUI_INPUT_PASS;
}

void treeGenEditorPlugin::edited_scene_changed()
{
    // this detects if you have swapped scenes
    //print_line("yo science");
}

void treeGenEditorPlugin::selected_notify()
{
    print_line("jeeeeeeesus");
}

treeGenEditorPlugin::treeGenEditorPlugin()
{
    auto tmp = EditorPlugin::get_editor_interface();
    selectionHandle = tmp->get_selection();
    if(!selectionHandle->is_connected("selection_changed",callable_mp(this,&treeGenEditorPlugin::_editor_has_selected)))
        selectionHandle->connect("selection_changed",callable_mp(this,&treeGenEditorPlugin::_editor_has_selected));
    test_control=nullptr;
    count=0;
}

treeGenEditorPlugin::~treeGenEditorPlugin()
{
    //not disconnecting for now
    if(test_control)
        memdelete(test_control);
    selectionHandle= nullptr;
    test_control=nullptr;
}
