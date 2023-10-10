#include <iostream>
#include <vector>
#include <algorithm>

class Slices {
private:
    std::vector<int> data;
    std::vector<std::vector<int>> slices;

    // Private method to fill 'data' with evenly spaced integers
    void fillData(int start_index, int end_index) {
        data.clear();
        data.resize(end_index - start_index);
        std::generate(data.begin(), data.end(), [start_index]() mutable {
            return start_index++;
        });
    }

    // Private method to slice 'data' into pieces size of 'slices_elements' value
    void sliceData(int slices_elements) {
        slices.clear();
        for (size_t i = 0; i < data.size(); i += slices_elements) {
            slices.push_back(std::vector<int>(data.begin() + i, data.begin() + std::min(i + slices_elements, data.size())));
        }
    }

public:
    // Constructor that initializes 'data' and 'slices'
    Slices(int start_index, int end_index, int slices_elements) {
        fillData(start_index, end_index);
        sliceData(slices_elements);
    }

    // Iterator for iterating over 'slices' vector
    class Iterator {
    private:
        const Slices& slicer;
        size_t index;

    public:
        Iterator(const Slices& s, size_t i) : slicer(s), index(i) {}

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }

        void operator++() {
            index++;
        }

        const std::vector<int>& operator*() const {
            return slicer.slices[index];
        }
    };

    Iterator begin() const {
        return Iterator(*this, 0);
    }

    Iterator end() const {
        return Iterator(*this, slices.size());
    }
};

// Overload the << operator for std::vector<int>
std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    for (int num : vec) {
        os << num << " ";
    }
    return os;
}

int main() {

    {
        std::cout << "Example 1:" << std::endl;
        auto slicer = Slices(0, 6, 3);
        int slice_count = 0;
        for (auto slice: slicer) {
            std::cout << "Indices of Slice " << slice_count++ << ": "
                        << slice << std::endl;
        }
        std::cout << std::endl;
    }

    {
        std::cout << "Example 2:" << std::endl;
        auto slicer = Slices(1, 6, 3);
        int slice_count = 0;
        for (auto slice: slicer) {
            std::cout << "Indices of Slice " << slice_count++ << ": "
                      << slice << std::endl;
        }
        std::cout << std::endl;
    }

    {
        std::cout << "Example 3:" << std::endl;
        auto slicer = Slices(1, 10, 4);
        int slice_count = 0;
        for (auto slice: slicer) {
            std::cout << "Indices of Slice " << slice_count++ << ": "
                      << slice << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}