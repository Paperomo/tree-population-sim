#include "treeGenServerServerInteractions.h"
#include "treeGenServer.h"
#include "scene/main/window.h"

treeGenServerServerInteractions * treeGenServerServerInteractions::singleton=nullptr;
void treeGenServerServerInteractions::_bind_methods()
{
    //hmmmmmm.
    ADD_SIGNAL(MethodInfo("enter_tree"));
}

void treeGenServerServerInteractions::_notification(int p_what)
{
    
}

bool treeGenServerServerInteractions::create_singleton(SceneTree *st)
{
    if (st == nullptr)
    {
        return false;
    }
    //Window;
    Node *root = st->get_root();
    for (int i = 0; i < root->get_child_count(); ++i)
    {
        treeGenServerServerInteractions *u = Object::cast_to<treeGenServerServerInteractions>(root->get_child(i));
        if (u != nullptr)
        {
            return false; //currently attached to here.
        }
    }
    //so now we are in the situation where there are no attached tree gen servers.
    //oh but how do we tell if they delete themselves. huh.
    if(treeGenServerServerInteractions::singleton)
    {
        //in reality this should never happen since it would be inbetween scenes I guess?
        //might want to figure out what to do if its inbetween scenes
        Node* daddy =treeGenServerServerInteractions::singleton->get_parent();
        if(daddy)
        {
            //else headless
            daddy->remove_child(treeGenServerServerInteractions::singleton);
        }
           
    }
    else
    {
        treeGenServerServerInteractions::singleton = memnew(treeGenServerServerInteractions);
    }
    root->add_child(treeGenServerServerInteractions::singleton);
    return true;
    //this might apparently leak but so be it, i guess.
}

treeGenServerServerInteractions *treeGenServerServerInteractions::get_singleton()
{
    return treeGenServerServerInteractions::singleton;
}

treeGenServerServerInteractions::treeGenServerServerInteractions() :Node()
{
    if(singleton)
    {
        //assert an error here
        //maybe attempt to delete self?
        return;
    }
    //for some reason all the singleton references I've seen do not check if one has been instantiated already? this seems not safe.
    singleton = this;
    set_name("do_not_touch_this");
    set_process(true);
    set_process_mode(PROCESS_MODE_ALWAYS);
}

treeGenServerServerInteractions::~treeGenServerServerInteractions()
{
    if(this == treeGenServerServerInteractions::singleton)
    {
        //then im being deleted for reals, its safer to be deleted since jumping around headless
        //makes absolutely no sense.
        treeGenServerServerInteractions::singleton = nullptr;
    }
}
