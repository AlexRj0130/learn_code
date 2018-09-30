# -*- coding: utf-8 -*-

import pandas as pd 
import os 


file_dir = "./"
file_name = "court_0905-0927_id-source-date.csv"


# 如果 csv 文件中的数据部分，在引号中，那么使用 pandas 读取文件后，将转化为 numpy.int64 类型
# 本次测试 csv 文件中的数据部分，不在引号中，
# 

def main():
    file_abs_path = os.path.join(file_dir, file_name)
    with open(file_abs_path, "r") as csv_file:
        data = pd.read_csv(csv_file)
        print data


if __name__ == '__main__':
    main()
    