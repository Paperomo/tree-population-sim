#include "treeGenNode.h"
#include "treeGenServer.h"
#include "treeGenServerServerInteractions.h"
#include "core/os/os.h"
void treeGenNode::_bind_methods() {
}

void treeGenNode::_notification(int p_what)
{
    switch(p_what)
    {
        case NOTIFICATION_ENTER_TREE:
            print_line("_how_notifcations_work");
            ++count;
            if(count == 1)
            {
                //reparent it else remake it?
                
            }
            //this fires whenever reparented too wth
        break;
        default:

        break;

    };
    
}

treeGenNode::treeGenNode():MeshInstance3D() {

}
