#include "treeGenServer.h"

#include "core/variant/dictionary.h"
#include "core/os/os.h"
//now we just need to store the data and figure out how to modify it.
//#include "prime_225.h"

void treeGenServer::thread_func(void *p_udata){

    treeGenServer *ac = (treeGenServer *) p_udata;
    uint64_t msdelay = 1000;

    while (!ac->exit_thread){
        
            ac->lock();
            ac->core_treegen_loop();
            //is this constantly running
            ///++counter;
            ac->unlock();
        
        OS::get_singleton()->delay_usec(msdelay * 1000);
    }
}

Error treeGenServer::init(){
    if(singleton != this){return FAILED;}
    thread_exited = false;
    counter = 0;
    mutex = memnew(Mutex); //well god knows whats gone wrong here//
    thread = memnew(Thread);
    //adopting this from audio_stream_preview
    thread->start(treeGenServer::thread_func, this);
    //&Thread(treeGenServer::thread_func, this);//Thread::create();
    return OK;
}

treeGenServer *treeGenServer::singleton = NULL;

treeGenServer *treeGenServer::get_singleton() {
    return singleton;
}

void treeGenServer::core_treegen_loop()
{
    
    print_line("are you here?");
    singleton->counter++;
    
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
    if (!thread) {
        return;
    }
    
    exit_thread = true;
    thread->wait_to_finish();
    //Thread::wait_to_finish(thread);

    memdelete(thread);

    if (mutex) {
        memdelete(mutex);
    }

    thread = NULL;
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
}

void treeGenServer::connect_signals() {

}

Variant treeGenServer::simple_output_test()
{
    if (get_singleton())
    {
        return Variant(get_singleton()->counter);
    }
    else
    {
        return Variant("Error");
    }
}

int treeGenServer::get_something() const {
	return counter;
}

treeGenServer::treeGenServer(){
    if(singleton)
    {
        print_error("not supposed to be here");
        return;
    }
    print_line("This is init");
	//for some reason all the singleton references I've seen do not check if one has been instantiated already? this seems not safe.
    singleton = this;
}