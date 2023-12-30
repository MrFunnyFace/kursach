#ifndef STATE_H
#define STATE_H

class State
{
    public:
    enum struct state{loading_page,main_menu,menu,show_list,standard_methods,unique_methods,add_obj,close,get_result};
    State();
    void set_state(state new_state);
    state get_state();
    ~State();
    private:
    State::state a;
};

#endif