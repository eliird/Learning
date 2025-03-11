#include<iostream>
#include<string>
#include <vector>

/*
Looking at some additional features of C++
*/

class Screen{
    /*
    You can make the functions of other class as friends instead of making the whole class a friend
    */
   friend void Window_mgr::some_function();
public:
    // you can define custom typedefs inside the class
    typedef std::string::size_type pos;

    Screen()=default;
    
   
    Screen(pos ht, pos wd, char c): 
        height(ht), width(wd), contents(ht *wd, c) {
            // std::cout << height << " , " << width << " , " << contents << std::endl;
        }
    
    char get() const {return contents[cursor];}

    // we can set function to be inline in declaration or definition, not both
    inline char get(pos ht, pos wd);
    Screen &move(pos r, pos c);

    void some_member() const{
        /*
        doing this is okay because we declared access_ctr as mutable;
        */
        ++this->acces_ctr;
    }

    /*
    functions that return *this
    */
    Screen &set(char);
    Screen &set(pos, pos, char);

    /*
    overloading based on const
    */
    Screen &display(std::ostream &os){
        std::cout << contents << std::endl;
        return *this;
    }

    const Screen &display(std::ostream &os) const{
        std::cout << contents << std::endl;
        return *this;
    }

private:

    //mutable keyword is used when this member can be modified even when class is declared as constant
    mutable size_t acces_ctr;
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};


class Window_mgr{
    private:
        // By default window manager has one blank screen
        std::vector<Screen> screens{Screen(24, 80, ' ')};
    public:
        void some_function();
        // void clear(ScreenIndex i);
};

//inlining in definition
inline
Screen &Screen::move(pos r, pos c){
    pos row = r * width;
    this->cursor = row + c;
    return *this;
}

// inlined in decalration
char Screen::get(pos r, pos c){
    pos row = r * width;
    return contents[row + c];
}

/*
functions that return *this;
functions that return *this are lvalues and can be used to chain functions together
e.g myScreen.move(0, 4).set('d'), because move returns lvalue we can chain it with set

Also need to be careful assume
myScreen.display(cout).set('*')
- in above function call if display returns a const reference than the aobve code is error
- to solve this we can overload based on const see inside definition of class above
*/
inline Screen &Screen::set(char c){
    contents[cursor] = c;
    return * this;
}

inline Screen &Screen::set(pos r, pos col, char ch){
    contents[r*width + col] = ch;
    return *this;
}




int main(){
    // you can access the typedef members of class using scope operators
    Screen::pos ht = 10, wd=20;
    Screen s(ht, wd, 'c');

}