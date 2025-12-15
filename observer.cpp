#include <iostream>
#include <memory>
#include <map>
#include <vector>
class Observer{
public:
    virtual void hasChange() =0;
    virtual ~Observer() = default;
};

class Subject{
public:
    virtual void subscribe(void* ptr, std::string & ip_address) =0;
    virtual void unsubscribe(void* ptr) =0;
    virtual void notifyAll()=0;
    virtual void notifyByIp(const std::string& ip) =0;
};
#define MAX_IP_SIZE 255
class Server: public Subject{
private:
    std::vector<std::shared_ptr<std::pair<std::string, Observer*>>> list_observer;
    std::string get_ip_address(){
        if (list_observer.size() > MAX_IP_SIZE){
            std::cout<<"Runout of command\n";
            return "";
        }
        if(list_observer.size() == 0){
            std::cout <<"has ip 1.1.1.2 available\n";
            return "1.1.1.2";
        }
        int ip_index_num = 3;
        for (ip_index_num;ip_index_num < MAX_IP_SIZE; ip_index_num ++){
            bool is_ip_used = false ;
            std::string ip_address = "1.1.1." + std::to_string(ip_index_num);
            for (auto it: list_observer){
                if( it && it->first == ip_address) is_ip_used = true;
            }
            if(is_ip_used) continue;
            std::cout << "new address declared: "<<ip_address <<"\n";
            return ip_address;
        }
        return "";

    }
public:
    void subscribe(void* ptr, std::string & ip_address) override{
        if(!ptr) return;
        Observer* observer = static_cast<Observer*> (ptr);
        std::string _ip_address = get_ip_address();
        if(_ip_address == "") {
            return;
        }
        std::shared_ptr<std::pair<std::string,Observer*>> p_observer =std::make_shared<std::pair<std::string,Observer*>>( _ip_address,observer );
        list_observer.push_back(p_observer);

        std::cout <<"created new client ip: "<<p_observer->first<<"\n";
        ip_address =  _ip_address;
    }

    void unsubscribe(void * ptr) override{
        if(!ptr) return;
        bool isOk = false;
        Observer* observer = static_cast<Observer*> (ptr);
        try {
            for (int i =0 ; i < list_observer.size(); i++){
                if(ptr == list_observer.at(i)->second){
                    isOk = true;
                    std::cout<< "Removed Ip: "<< list_observer.at(i)->first<<std::endl;
                    list_observer.erase(list_observer.begin() + i);
                }
            }
        }
        catch (const std::exception& message) {
            std::cout<< "[Error]"<<message.what()<<std::endl;
        }
    }
    void notifyAll() override {
        for (auto it: list_observer){
            it->second->hasChange();
        }
    }
    void notifyByIp(const std::string& ip) override{
        Observer* observer = nullptr;
        for (auto it: list_observer){
            if(it->first == ip){
                observer = it->second;
                observer->hasChange();
            }
        }
    }
};
class Client:public Observer{
    private:
    std::string ip;
    Subject* subject;
    public:
    Client(void * ptr ){
        ip = "";
        subject  = static_cast<Subject*> (ptr);
        subject->subscribe(this, ip);
        std::cout<<"[Client] subscribe success\n";
    }
    ~Client(){
        subject->unsubscribe(this);

    }
    void hasChange() override {
        printf("[Client] Ip: %s, Receive command from server\n", ip.c_str());
    }
};
int main(){
    Subject* subject = new Server();
    Observer* observer1 = new Client(subject);
    Observer* observer2 = new Client(subject);
    Observer* observer3 = new Client(subject);
    Observer* observer4 = new Client(subject);
    subject->notifyAll();
    subject->notifyByIp("1.1.1.3");
    delete(observer4);
    delete(observer3);
    delete(observer2);
    delete(observer1);
    
    
}