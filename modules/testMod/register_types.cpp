#include "register_types.h"
#include "core/object/class_db.h"
#include "core/os/os.h"
#include "core/config/engine.h"
#include "editor/inspector/editor_inspector.h"
#include "testMod.h"

void initialize_testMod_module(ModuleInitializationLevel p_level)
{
    switch(p_level)
    {
        case MODULE_INITIALIZATION_LEVEL_CORE:
            break;
        case MODULE_INITIALIZATION_LEVEL_SERVERS:
            {
                GDREGISTER_CLASS(testMod);
                // tree_Gen_Server = memnew(treeGenServer);
                // tree_Gen_Server->init();
                // ClassDB::register_class<treeGenServer>();
                // Engine::Singleton tTS_singleton = Engine::Singleton("treeTestServer", treeGenServer::get_singleton());
                // tTS_singleton.editor_only=true;
                // Engine::get_singleton()->add_singleton(tTS_singleton);
            }
            break;
        case MODULE_INITIALIZATION_LEVEL_SCENE:
              
            //GDREGISTER_INTERNAL_CLASS()
            break;
        case MODULE_INITIALIZATION_LEVEL_EDITOR:
            //EditorPlugins::add_by_type<treeGenEditorPlugin>();
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

void uninitialize_testMod_module(ModuleInitializationLevel p_level)
{
    switch(p_level)
    {
        case MODULE_INITIALIZATION_LEVEL_SERVERS:
            {
                
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
