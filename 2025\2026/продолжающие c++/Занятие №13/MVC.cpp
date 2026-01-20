#include <iostream>
#include <vector>
#include <map>
#include <string>

class TVChannel{
public:
	double frequency;
	std::string name;
	TVChannel(const double &frequency=0.0, const std::string name=""):frequency{frequency}, name{name}{}
};

class Model{
private:
	std::map<int, TVChannel> channels{};
	int current_channel=0, capacity;
public:
	Model(const int capacity):capacity{capacity}{}
	
	int add_channel(const int num, const TVChannel &channel){
		if(num>0){
			if(channels.count(num)>0){
				return 2;
			}else if(num <= capacity){
				channels.emplace(num, channel);
				return 0;
			}else{
				return 1;
			}
		}else{
			return 1;
		}
	}
	
	int remove_channel(const int &num){
		if(channels.count(num)>0){
			channels.erase(num);
			return 0;
		}else{
			return 1;
		}
	}
	
	int switch_channel(const int &num){
		if(num>0 and num<capacity){
			if(channels.count(num)>0){
				current_channel = num;
				return 0;
			}else{
				return 2;
			}
		}else{
			return 1;
		}
	}
	
	TVChannel get_current_channel(){
		return channels[current_channel];
	}
};

class View{
public:
	void display(const std::string &message)const{
		std::cout << message << "\n";
	}
};

std::vector<std::string> split(const std::string &line, const char &delimiter=' '){
	std::vector<std::string> result;
	int from=0, to;
	bool had_delimiter=false;
	for(to=0; to<line.size(); ++to){
		if(line[to]==delimiter){
			if(had_delimiter){
				from = to;
			}else{
				result.push_back(line.substr(from, to-from));
				had_delimiter=true;
				from = to;
			}
		}else if(had_delimiter){
			had_delimiter=false;
			from = to;
		}
	}
	if(to-from>0) result.push_back(line.substr(from, to-from));
	return result;
}

class Controller{
private:
	Model *model{nullptr};
	View *view{nullptr};
	
	int execute(const std::vector<std::string> &params){
		if(params[0].compare("exit")==0){
			return 0;
		}else if(params[0].compare("add")==0){
			if(params.size()!=4){
				view->display("Wrong parameters amount! - "+std::to_string(params.size()));
				return 1;
			}
			int result=0, num = std::stoi(params[1]);
			TVChannel channel{std::stod(params[2]), params[3]};
			do{
				result = model->add_channel(num, channel);
				switch(result){
					case 0:
						view->display("Channel succesfully added!");
						return 0;
					case 1:
						view->display("Incorrect channel number!\nChoose different number:\n");
						std::cin >> num;
						break;
					case 2:
						view->display("Channel under number "+params[1]+" already exists!\nRewrite?[y/n]" );
						std::string answer;
						std::cin >> answer;
						if(answer.compare("y")==0){
							model->remove_channel(num);
							result = model->add_channel(num, channel);
						}else return 1;
						break;
				}
			}while(result != 0);
		}else if(params[0].compare("remove")==0){
			if(params.size()!=2){
				view->display("Wrong parameters amount! - "+std::to_string(params.size()));
				return 1;
			}
			int num=std::stoi(params[1]);
			switch(model->remove_channel(num)){
				case 0:
					view->display("Channel succesully removed!");
					return 0;
				case 1:
					view->display("Channel don\'t exist to remove!");
					return 1;
				default: break;
			}
		}else if(params[0].compare("switch")==0){
			if(params.size()!=2){
				view->display("Wrong parameters amount! - "+std::to_string(params.size()));
				return 1;
			}
			switch(model->switch_channel(std::stoi(params[1]))){
				case 0:
					view->display("Watching channel "+model->get_current_channel().name);
					return 0;
				case 1:
					view->display("Illegal channl number!");
					return 1;
				case 2:
					view->display("Channel with this number was not registered!");
					return 1;
			}
		}
		return 1;
	}
public:
	Controller(Model *model, View *view):model{model}, view{view}{}
	
	void start(){
		std::string line;
		do{
			view->display("Enter command:");
			getline(std::cin, line);
			std::vector<std::string> params = split(line);
			execute(params);
		}while(line.compare("exit")!=0);
	}
};

int main(){
	View view{};
	Model model{10};
	Controller controller{&model, &view};
	controller.start();
	return 0;
}
