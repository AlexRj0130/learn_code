

class EsDelete():
    def __init__(self, es, index, doc_type):
        self.m_es = es
        self.m_index = index
        self.m_doc_type = doc_type

    def delete_all(self):
        query = {'query': {'match_all': {}}}
        self.m_es.delete_by_query(self.m_index, query, self.m_doc_type)