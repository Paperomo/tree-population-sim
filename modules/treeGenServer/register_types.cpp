#include "register_types.h"

#include "core/object/class_db.h"
#include "core/os/os.h"
#include "core/config/engine.h"
#include "editor/inspector/editor_inspector.h"
#include "treeGenServer.h"
#include "treeGenServerServerInteractions.h"
#include "treeGenNode.h"
#include "treeGenEditorPlugin.h"

static treeGenServer *tree_Gen_Server = NULL;


void initialize_treeGenServer_module(ModuleInitializationLevel p_level)
{
    //print_line("init is called");
    switch(p_level)
    {
        case MODULE_INITIALIZATION_LEVEL_CORE:
            break;
        case MODULE_INITIALIZATION_LEVEL_SERVERS:
            {
                print_line("creating server");
                //probably will do well with some os hints
                tree_Gen_Server = memnew(treeGenServer);
                tree_Gen_Server->init();
                ClassDB::register_class<treeGenServer>();
                Engine::Singleton tTS_singleton = Engine::Singleton("treeTestServer", treeGenServer::get_singleton());
                tTS_singleton.editor_only=true;
                Engine::get_singleton()->add_singleton(tTS_singleton);
            }
            break;
        case MODULE_INITIALIZATION_LEVEL_SCENE:
            GDREGISTER_CLASS(treeGenServerServerInteractions);
            GDREGISTER_CLASS(treeGenNode);
            //GDREGISTER_INTERNAL_CLASS()
            break;
        case MODULE_INITIALIZATION_LEVEL_EDITOR:
            EditorPlugins::add_by_type<treeGenEditorPlugin>();
            //EditorInspector::add_inspector_plugin(memnew(treeGenNodeInspectorProperties));
            //EditorPlugins::add_by_type<treeGenNodeInspectorProperties>();
            break;
        default:
            break;
    }
    //if(just_seeing_if_it_exists) print_line("THIS IS REGISTERED");
    //print_line("init was called");
    //if(MODULE_INITIALIZATION_LEVEL_EDITOR){}
    

    
    
}

void uninitialize_treeGenServer_module(ModuleInitializationLevel p_level)
{
    //print_line("uninit is called");
    switch(p_level)
    {
        case MODULE_INITIALIZATION_LEVEL_SERVERS:
            {//nameless scope just to facilitate working inside a switch case since switch cases dont allow defining stuff since they are jump tables which is understandable.
                if (tree_Gen_Server)
                {
                    print_line("removing server");// what the fuck?
                    tree_Gen_Server->finish();
                    Engine::get_singleton()->remove_singleton("treeTestServer");
                    memdelete(tree_Gen_Server);
                    tree_Gen_Server=nullptr;
                    //[come back] print_line("closing gracefully");
                }
            }
            break;
        case MODULE_INITIALIZATION_LEVEL_CORE:
            {
            }
            break;
        case MODULE_INITIALIZATION_LEVEL_SCENE:
            {
            }
            break;
        case MODULE_INITIALIZATION_LEVEL_EDITOR:
            {

            }
            break;
        default:
            break;
    }
    
}
