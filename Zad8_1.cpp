#include <iostream>

using namespace std;
struct node
{
int item; node* next;
node (int z, node* t = 0)
{ item = z; next = t; }
};
typedef node* link;

link scal(link head1, link head2){
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    if (head1->item < head2->item) {
        head1->next = scal(head1->next, head2);
        return head1;
    }
    else {
        head2->next = scal(head1, head2->next);
        return head2;
    }

}
void ShowList(link n){
    while(n!=NULL){
        cout<<n->item<<' ';
        n=n->next;
    }
}


int main()
{   int tests,n,m,d;
    cin>>tests;
    for(int i=0;i<tests;i++){
        cin>>n>>m;
        cin>>d;
        link head1=NULL;
        link tail1=head1;
        head1=new node(d);
        tail1=head1;
        for(int i=1;i<n;i++){
                cin>>d;
                tail1->next=new node(d);
                tail1=tail1->next;
        }
        cin>>d;
        link head2=NULL;
        link tail2=head2;
        head2=new node(d);
        tail2=head2;
        for(int i=1;i<m;i++){
                cin>>d;
                tail2->next=new node(d);
                tail2=tail2->next;
        }
        link scalone=scal(head1,head2);
        ShowList(scalone);
        cout<<endl;



    }

    return 0;
}
