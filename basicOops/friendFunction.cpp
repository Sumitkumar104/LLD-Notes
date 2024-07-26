// A friend function is not the member of a class but still have access to its private and protected members.
class area
{
    private:
    int l;
    int b;
    
    area(int l,int b)
    {
        this->l=l;
        this->b=b;
    }
    public:
   friend int volume(area a);
};

// here we can access the private member of class area i.e l and b
int volume(area a){
    return a.b*a.l;
}
