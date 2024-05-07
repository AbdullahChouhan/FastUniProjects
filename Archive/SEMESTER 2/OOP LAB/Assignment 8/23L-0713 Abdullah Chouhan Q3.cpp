#include <iostream>
#include <string>
#include <vector>

class Device {
    private:
        int deviceId;
        std::string deviceType;
        bool status;
    public:
        Device(int deviceId, const std::string& deviceType, bool status) : deviceId(deviceId), deviceType(deviceType), status(status) {}

        Device(const Device& obj) : deviceId(obj.deviceId), deviceType(obj.deviceType), status(obj.status) {}

        void setDeviceId(int deviceId) {
            this->deviceId = deviceId;
        }
        void setDeviceType(const std::string& deviceType) {
            this->deviceType = deviceType;
        }
        void setStatus(bool status) {
            this->status = status;
        }
        int getDeviceId() const {
            return deviceId;
        }
        std::string getDeviceType() const {
            return deviceType;
        }
        bool getStatus() const {
            return status;
        }
        void Toggle() {
            status = !status;
        }
};

class SmartHome {
    private:
        std::vector<Device> devices;
    public:
        SmartHome() {}
        SmartHome(const SmartHome& obj) : devices(obj.devices) {}

        void addDevice(const Device& device) {
            for (auto& d : devices) {
                if (d.getDeviceId() == device.getDeviceId()) {
                    std::cout << "Device with ID " << device.getDeviceId() << " already exists." << "\n";
                    return;
                }
            }
            devices.emplace_back(device);
        }
        void removeDevice(int deviceId) {
            for (auto it = devices.begin(); it != devices.end(); it++) {
                if (it->getDeviceId() == deviceId) {
                    devices.erase(it);
                    break;
                }
            }
        }
        void display() {
            for (const auto& d : devices) {
                std::cout << d.getDeviceId() << " " << d.getDeviceType() << " " << d.getStatus() << "\n";
            }
        }
};

int main() {
    SmartHome smartHome;
    smartHome.addDevice(Device(1, "light", true));
    smartHome.addDevice(Device(2, "fan", false));
    std::cout << "Devices before removal: " << "\n";
    smartHome.display();
    smartHome.removeDevice(1);
    std::cout << "Devices after removal: " << "\n";
    smartHome.display();
}