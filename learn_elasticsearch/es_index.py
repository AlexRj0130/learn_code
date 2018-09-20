

class EsIndex():
    def __init__(self, es, index, doc_type, datas, id = None):
        self.m_es = es
        self.m_index = index
        self.m_doc_type = doc_type
        self.m_id = id
        self.m_datas = datas

    def index(self):
        for data in self.m_datas:
            self.m_es.index(self.m_index, self.m_doc_type, data, self.m_id)
    