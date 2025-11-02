#include "treeGenServer.h"
#include "treeGenServerServerInteractions.h"
#include "core/variant/dictionary.h"
#include "core/os/os.h"
//#include "tree_gen_api.h"
treeGenServer *treeGenServer::singleton = NULL;
//now we just need to store the data and figure out how to modify it.
void treeGenServer::notification_methods() {
    //[come back] print_line("test");
}
void treeGenServer::thread_func(void *p_udata){
    //print_line(vformat("My name is %d.", (int)p_udata));
    //vformat();
    
    treeGenServer *ac = (treeGenServer *) p_udata;
    uint64_t msdelay = 1000;
    //ac->connect();
    while (!ac->exit_thread)
    {
        if(!Engine::get_singleton()->is_editor_hint())
            continue;
            ac->lock();
            ac->core_treegen_loop();
            ac->unlock();
    }
    if(ac->exit_thread == true)
    {
        //print_line("hoi im temmi");
    }
}

void treeGenServer::linkUp()
{
    get_singleton()->connect("enter_tree",callable_mp(get_singleton(),&treeGenServer::notification_methods));
}

Error treeGenServer::init(){
    if(singleton != this)
    {
        //print_line("HOI WTH");
        //so this never happens for some reason.
        //const int hw_threads_hint = Thread::get_hardware_concurrency();
        return FAILED;
    }
    exit_thread = false;
    thread_exited = false;
    counter = 0;
    mutex = memnew(Mutex); //well god knows whats gone wrong here//
    thread = memnew(Thread);
    //adopting this from audio_stream_preview
    thread->start(treeGenServer::thread_func, this);
    //&Thread(treeGenServer::thread_func, this);//Thread::create();
    //ADD_SIGNAL();
    //
    return OK;
}



treeGenServer *treeGenServer::get_singleton() {
    if(singleton == nullptr)
        print_error("err");
    return treeGenServer::singleton;
}

void treeGenServer::core_treegen_loop()
{
    // const Engine * tmpEditorPtr = Engine::get_singleton();
    // tmpEditorPtr->is_editor_hint();
    // tmpEditorPtr->is_embedded_in_editor();
    // tmpEditorPtr->is_editor_hint();
    //print_line("loop singleton");
    if (Engine::get_singleton()->is_editor_hint())
    {
        //print_line("loop singleton");
        //double quack = duck::Arithmetic().Add(1,2);
        //print_line(quack);
        singleton->counter++;
    }
    else
    {
        //print_line("not_editor");
    }
    //okay so that works.
    // for (Set<RID>::Element *e = buses.front(); e; e = e->next()) {
    //     auto bus = bus_owner.getornull(e->get());

    //     if (bus) {
    //         uint64_t room = bus->next_room();
    //         _emit_occupy_room(room, bus->get_self());
    //     }
    // }
}

void treeGenServer::unlock() {
    if (!thread || !mutex) {
        return;
    }
    mutex->unlock();
}

void treeGenServer::lock() {
    if (!thread || !mutex) {
        return;
    }
    mutex->lock();
}

//void treeGenServer::_emit_occupy_room(uint64_t room, RID rid) {
//    _treeGenServer::get_singleton()->_occupy_room(room, rid);
//}
//
//Variant treeGenServer::get_bus_info(RID id) {
//    InfiniteBus *bus = bus_owner.getornull(id);
//
//    if (bus) {
//        Dictionary d;
//        d["prime"] = bus->get_bus_num();
//        d["current_room"] = bus->get_current_room();
//        return d;
//    }
//
//    return Variant();
//}
//
void treeGenServer::finish(){
    if (thread)
    {
        exit_thread = true;
        thread->wait_to_finish();
    //Thread::wait_to_finish(thread);
        //print_line("THIS IS REACHED");
        memdelete(thread);
        thread = nullptr;
    }
    if (mutex)
    {
        memdelete(mutex);
        mutex = nullptr;
    }


}



// RID treeGenServer::create_bus() {
//     lock();
//     InfiniteBus *ptr = memnew(InfiniteBus(PRIME[counter++]));
//     RID ret = bus_owner.make_rid(ptr);
//     ptr->set_self(ret);
//     buses.insert(ret);
//     unlock();

//     return ret;
// }

// // https://github.com/godotengine/godot/blob/master/core/templates/rid.h
// bool treeGenServer::delete_bus(RID id) {
//     if (bus_owner.owns(id)) {
//         lock();
//         InfiniteBus *b = bus_owner.get(id);
//         bus_owner.free(id);
//         buses.erase(id);
//         memdelete(b);
//         unlock();
//         return true;
//     }

//     return false;
// }

// void treeGenServer::clear() {
//     for (Set<RID>::Element *e = buses.front(); e; e = e->next()) {
//         delete_bus(e->get());
//     }
// }

// bool treeGenServer::empty() {
//     return buses.size() <= 0;
// }

void treeGenServer::_bind_methods() {
    //I dont think theres really anything to bind here yet.
    
    ClassDB::bind_method(D_METHOD("simple_output_test"), &treeGenServer::simple_output_test);
    ClassDB::bind_method(D_METHOD("_node_entered_tree"), &treeGenServer::notification_methods);
}

void treeGenServer::_notification(int p_what)
{
    //Object::NOTIFICATION_POSTINITIALIZE
    //print_line(vformat("%d %d", (int)this,p_what));
    //this is kinda useless for now.
    //print_line(p_what);
    //what is the enum
    
}

void treeGenServer::connect_signals()
{
    
}

Variant treeGenServer::simple_output_test()
{
    if (treeGenServer::get_singleton())
    {
        return Variant(treeGenServer::get_singleton()->counter);
    }
    else
    {
        return Variant("Error");
    }
}

int treeGenServer::get_something() const
{
    //should lock and unlock
    //int tmp_out = 0;''
	return counter;
}

treeGenServer::treeGenServer():Object(){
    if(singleton)
    {
        print_error("not supposed to be here");
        return;
    }
    //print_line("This is init");
	//for some reason all the singleton references I've seen do not check if one has been instantiated already? this seems not safe.
    singleton = this;
}
















