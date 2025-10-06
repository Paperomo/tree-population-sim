#include "treeGenEditorPlugin.h"
#include "scene/gui/check_box.h"
void treeGenEditorPlugin::_bind_methods() {
}

void treeGenEditorPlugin::_notification(int p_what) {
	switch(p_what)
    {
        case NOTIFICATION_ENTER_TREE:
            //so this gets attached to the editor... why not just run the singleton here then lol
            ++count;
            if(count == 1)
            {
                auto tmp = EditorPlugin::get_editor_interface();
                if(!test_control)
                    test_control = memnew(CheckBox);
                add_control_to_container(CONTAINER_SPATIAL_EDITOR_SIDE_LEFT,test_control);
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

treeGenEditorPlugin::treeGenEditorPlugin() {
    test_control=nullptr;
    count=0;
}

treeGenEditorPlugin::~treeGenEditorPlugin() {
    if(test_control)
        memdelete(test_control);
    
    test_control=nullptr;
}
