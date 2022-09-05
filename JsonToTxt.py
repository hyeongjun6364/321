import json
import os

folder_path_json = "C:/Users/user/Desktop/fileload" #json file load path
folder_path_txt = "C:/Users/user/Desktop/fileload"  #txt파일 save path

def CocoJsonToYoloFormat(path) :
    with open(path,'r', encoding='UTF-8') as f :
        json_data = json.load(f)

    # print(json.dumps(json_data, indent="\t"))

    images = json_data['images'][0]
    width = images['width']
    height = images['height']

    annotations = json_data['annotations']
    output = []
    for i in range(len(annotations)) :
        annotation = annotations[i]
        id = annotation['id']
        bbox = annotation['bbox']

        x = bbox[0] / width    # rate of x
        y = bbox[1] / height   # rate of y
        w = bbox[2] / width    # rate of width
        h = bbox[3] / height   # rate of height

        output.append([id, x, y, w, h])
    return output

def saveYoloToTxt(file_name,save_data):
    with open(file_name, 'w', encoding='UTF-8') as f_txt :
        for i in range(len(save_data)):
            save_yoloform = save_data[i]
            f_txt.write('%g %.6f %.6f %.6f %.6f' %(save_yoloform[0],save_yoloform[1],save_yoloform[2],save_yoloform[3],save_yoloform[4]))
            if(i != len(save_data)-1) :
                f_txt.write('\n')

fileEx = r'.json'
file_name_list = [file for file in os.listdir(folder_path_json) if file.endswith(fileEx)]

num_json = len(file_name_list)

for index_json in range(num_json) : 
    file_name = file_name_list[index_json]
    path_json = folder_path_json + os.sep + file_name
    # Load
    yolo_data = CocoJsonToYoloFormat(path_json)

    # Save
    path_txt =  folder_path_txt + os.sep + file_name[0:-4]+'txt'
    saveYoloToTxt(path_txt,yolo_data)

    print("process : %d / %d (%d %%) [file : "%(index_json+1,num_json,(index_json+1)*100/num_json)+file_name+"\n" )