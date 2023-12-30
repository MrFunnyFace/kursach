#include "../UI/state.h"

State::State()
{
    a=state::loading_page; 
}

void State::set_state(State::state new_state)
{
    a=new_state;
}

State::state State::get_state()
{
    return a;
}

State::~State(){}
