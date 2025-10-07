#ifndef TREE_GEN_NODE_EDITOR_PLUGIN_H
#define TREE_GEN_NODE_EDITOR_PLUGIN_H
#include "editor/inspector/editor_inspector.h"
#include "editor/plugins/editor_plugin.h"
#include "scene/gui/dialogs.h"
class EditorSelection;
class Callable;
class treeGenEditorPlugin : public EditorPlugin
{
    GDCLASS(treeGenEditorPlugin, EditorPlugin)
    //LETS MAKE THIS SEPARATE FOR THE MEANWHILE TO SEE IF I CAN ATTACH IT ON
    Control* test_control=nullptr;
    EditorSelection* selectionHandle=nullptr;
    unsigned count=0;
    protected:
        static void _bind_methods();
        void _notification(int p_what);
    public:
        void  _editor_has_selected();
        void  edit (Object *p_object);
        bool handles(Object *p_object) const final;
        bool forward_canvas_gui_input (const Ref< InputEvent > &p_event);
        EditorPlugin::AfterGUIInput  forward_3d_gui_input(Camera3D *p_camera, const Ref< InputEvent > &p_event);
        void edited_scene_changed ();
        String get_plugin_name() const { return "treeGen"; };
        void selected_notify();
        treeGenEditorPlugin();
        ~treeGenEditorPlugin();
};

#endif