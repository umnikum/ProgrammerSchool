#include <iostream>
#include <string>

enum State{
	IDDLE,
	WORKING,
	FINISHED
};

class Event{
public:
	int code;
	std::string message{};
	Event(const int &code, const std::string &message = ""):code{code}, message{message}{}
};

class EventListener{
public:
	enum EventCode{
		FINISH,
		MESSAGE,
		ERROR
	};
	State state{State::IDDLE};

	void receive(const Event &event){
		state = State::WORKING;
		switch(event.code){
			case FINISH:
				state = State::FINISHED;
				break;
			case MESSAGE:
				std::cout << "Message: " << event.message << "\n";
				break;
			case ERROR:
			default:
				std::cout << "Error occured: " << event.message << "\n";
		}
	}
};

int main(){
	EventListener listener{};
	while(listener.state != State::FINISHED){
		std::string line;
		std::cin >> line;
		if(line.compare("exit") == 0){
			listener.receive({EventListener::EventCode::FINISH});
		}else{
			listener.receive({EventListener::EventCode::MESSAGE, line});
		}
	}
	listener.receive({EventListener::EventCode::ERROR, "Error message!"});
}
