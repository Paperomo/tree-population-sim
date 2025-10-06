#ifndef TREE_GEN_NODE_EDITOR_PLUGIN_H
#define TREE_GEN_NODE_EDITOR_PLUGIN_H
#include "editor/inspector/editor_inspector.h"
#include "editor/plugins/editor_plugin.h"
#include "scene/gui/dialogs.h"
class treeGenEditorPlugin : public EditorPlugin
{
    GDCLASS(treeGenEditorPlugin, EditorPlugin)
    //LETS MAKE THIS SEPARATE FOR THE MEANWHILE TO SEE IF I CAN ATTACH IT ON
    Control* test_control=nullptr;
    unsigned count=0;
    protected:
        static void _bind_methods();
        void _notification(int p_what);
    public:
	virtual String get_plugin_name() const override { return "treeGen"; }
    treeGenEditorPlugin();
    ~treeGenEditorPlugin();
};

#endif