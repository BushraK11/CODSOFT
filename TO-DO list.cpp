#include <iostream>
#include <string>

using namespace std;
class Task {
private:
    string description;
    bool completed;
public:
    Task(string desc) : description(desc), completed(false) {}
    void markCompleted() {
        completed = true;
    }
    void markPending() {
        completed = false;
    }
    bool isCompleted() {
        return completed;
    }
    string getDescription() {
        return description;
    }
};

class ToDoList {
private:
    static const int MAX_TASKS = 100;
    Task* tasks[MAX_TASKS];
    int numTasks;

public:
    ToDoList() : numTasks(0) {}

    void addTask(string description) {
        if (numTasks < MAX_TASKS) {
            tasks[numTasks++] = new Task(description);
            cout << "Task added successfully." << endl;
        } else {
            cout << "Cannot add more tasks. The list is full." << endl;
        }
    }
    void viewTasks() {
        if (numTasks == 0) {
            cout << "No tasks in the list." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (int i = 0; i < numTasks; ++i) {
                cout << (i + 1) << ". " << tasks[i]->getDescription();
                if (tasks[i]->isCompleted()) {
                    cout << " - Completed" << endl;
                } else {
                    cout << " - Pending" << endl;
                }
            }
        }
    }
    void markTaskCompleted(int index) {
        if (index >= 1 && index <= numTasks) {
            tasks[index - 1]->markCompleted();
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }
	void removeTask(int index) {
        if (index >= 1 && index <= numTasks) {
            delete tasks[index - 1];
            for (int i = index - 1; i < numTasks - 1; ++i) {
                tasks[i] = tasks[i + 1];
            }
            numTasks--;
            cout << "Task removed successfully." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }
    ~ToDoList() {
        for (int i = 0; i < numTasks; ++i) {
            delete tasks[i];
        }
    }
};

int main() {
    ToDoList todo;
    int choice;
    string desc;
    int index;

    do {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, desc);
                todo.addTask(desc);
                break;
            case 2:
                todo.viewTasks();
                break;
            case 3:
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todo.markTaskCompleted(index);
                break;
            case 4:
                cout << "Enter task index to remove: ";
                cin >> index;
                todo.removeTask(index);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}



















//#include<iostream>
//using namespace std;
//int main(){
//	int choice;
//	int list[20];
//	cout<< "Enter your choice"<<endl;
//	cout<<"1.Input tasks "<<endl;
//	cout<<"2.View tasks "<<endl;
//	cout<<"3.Mark task as completed "<<endl;
//	cout<<"4.Delete tasks "<<endl;
//	cout<<"Choice : "<<endl;
//	cin>>choice;
//	
//	switch(choice){
//		case 1:{
//			
//			break;
//		}
//	}
//}
//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//void loadImage(Mat &image) {
//    string imagePath;
//    cout << "Enter image path: ";
//    cin >> imagePath;
//    image = imread(imagePath, IMREAD_COLOR);
//    if (image.empty()) {
//        cout << "Could not open or find the image" << endl;
//        exit(0);
//    }
//}
//
//void displayImage(const Mat &image) {
//    namedWindow("Image", WINDOW_NORMAL);
//    imshow("Image", image);
//    waitKey(0);
//}
//
//void applyFilter(Mat &image, int filter) {
//    Mat filteredImage;
//    switch (filter) {
//        case 1:
//            cvtColor(image, filteredImage, COLOR_BGR2GRAY);
//            break;
//        case 2:
//            GaussianBlur(image, filteredImage, Size(5, 5), 0, 0);
//            break;
//        case 3:
//            Mat kernel = (Mat_<float>(3, 3) << -1, -1, -1, -1, 9, -1, -1, -1, -1);
//            filter2D(image, filteredImage, -1, kernel);
//            break;
//        default:
//            cout << "Invalid filter option" << endl;
//            return;
//    }
//    image = filteredImage;
//}
//
//void adjustColor(Mat &image, int brightness, int contrast) {
//    Mat adjustedImage;
//    double alpha = (double)brightness / 100 + 1;
//    double beta = (double)contrast / 100;
//    adjustedImage = image.clone();
//    for (int y = 0; y < image.rows; y++) {
//        for (int x = 0; x < image.cols; x++) {
//            for (int c = 0; c < 3; c++) {
//                double i = image.at<Vec3b>(y, x)[c];
//                i = saturate_cast<uchar>(alpha * i + beta);
//                adjustedImage.at<Vec3b>(y, x)[c] = i;
//            }
//        }
//    }
//    image = adjustedImage;
//}
//
//void cropAndResize(Mat &image, int operation) {
//    Rect roi;
//    switch (operation) {
//        case 1:
//            roi = Rect(0, 0, image.cols / 2, image.rows / 2);
//            break;
//        case 2:
//            roi = Rect(image.cols / 4, image.rows / 4, image.cols / 2, image.rows / 2);
//            break;
//        case 3:
//            roi = Rect(image.cols / 2, 0, image.cols / 2, image.rows);
//            break;
//        case 4:
//            roi = Rect(0, image.rows / 2, image.cols, image.rows / 2);
//            break;
//        default:
//            cout << "Invalid crop and resize option" << endl;
//            return;
//    }
//    Mat croppedImage = image(roi);
//    resize(croppedImage, image, Size(), 2, 2, INTER_CUBIC);
//}
//
//void saveImage(const Mat &image) {
//    string savePath;
//    cout << "Enter save path: ";
//    cin >> savePath;
//    imwrite(savePath, image);
//}
//
//int main() {
//    Mat image;
//    int operation;
//
//    loadImage(image);
//    displayImage(image);
//
//    while (true) {
//        cout << "Choose operation:" << endl;
//        cout << "1. Load image" << endl;
//        cout << "2. Display image" << endl;
//        cout << "3. Apply filter" << endl;
//        cout << "4. Adjust color" << endl;
//        cout << "5. Crop and resize" << endl;
//        cout << "6. Save image" << endl;
//        cout << "7. Exit" << endl;
//        cin >> operation;
//
//        switch (operation) {
//            case 1:
//                loadImage(image);
//                break;
//            case 2:
//                displayImage(image);
//                break;
//            case 3: {
//                int filter;
//                cout << "Choose filter:" << endl;
//                cout << "1. Grayscale" << endl;
//                cout << "2. Blur" << endl;
//                cout << "3. Sharpen" << endl;
//                cin >> filter;
//                applyFilter(image, filter);
//                break;
//            }
//            case 4: {
//                int brightness, contrast;
//                cout << "Enter brightness adjustment (0-200): ";
//                cin >> brightness;
//                cout << "Enter contrast adjustment (0-200): ";
//                cin >> contrast;
//                adjustColor(image, brightness, contrast);
//                break;
//            }
//            case 5: {
//                int operation;
//                cout << "Choose crop and resize option:" << endl;
//                cout << "1. Top left quarter" << endl;
//                cout << "2. Center square" << endl;
//                cout << "3. Top right quarter" << endl;
//                cout << "4. Bottom left quarter" << endl;
//                cin >> operation;
//                cropAndResize(image, operation);
//                break;
//            }
//            case 6:
//                saveImage(image);
//                break;
//            case 7:
//                exit(0);
//            default:
//                cout << "Invalid operation" << endl;
//                break;
//        }
//    }
//
//    return 0;
//}