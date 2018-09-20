# -*- coding: utf-8 -*-

from elasticsearch import Elasticsearch

import conf
import datas
import es_index
import es_query
import es_delete

def init_es(host, port):
    es = Elasticsearch([{'host': host, 'port': port}])
    return es

def print_dic(data_tmp, indent_count = 0):
    if None == data_tmp:
        return
    data = data_tmp.copy()

    space = ""
    for i in range(0, indent_count):
        if 0 == i % 4:
            space += '|'
        else:
            space += " "

    if isinstance(data, dict):
        for key, value in data.items():
            if isinstance(value, dict):
                print space + str(key) + ": "
                print_dic(value, indent_count + 4)
            elif isinstance(value, list):
                print space + str(key) + ": "
                for item in value:
                    print_dic(item, indent_count + 4)
            else:
                print space + str(key) + ": " + str(value)
    elif isinstance(data, list):
        for item in data:
            if isinstance(item, dict):
                print_dic(item, indent_count + 4)
            elif isinstance(item, list):
                print_dic(item, indent_count + 4)
            else:
                print space + str(item) + " "
    else:
        print space + str(data) + " "

            

if __name__ == "__main__":
    es = init_es(conf.HOST, conf.PORT)
    
    # clean es
    # es_delete = es_delete.EsDelete(es, "people", "person")
    # es_delete.delete_all()

    # index data into es
    es_index = es_index.EsIndex(es, "people", "person", datas.DATAS)
    # es_index.index()

    # query es
    es_query = es_query.EsQuery(es, "people", "person")
    query_res = es_query.query_range(28, 28)
    # query_res = es_query.query_all()
    # query_res = es_query.query_match(28)
    # print(query_res)
    # print_dic(query_res)

    # query = {'query': { \
    #             'match': { \
    #                 'age': 28 }}}
    # query_res = es.search(None, None, query)
    # print "Now print all result..."
    print_dic(query_res)


    print("The end!!!")
