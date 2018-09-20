

class EsQuery():
    def __init__(self, es, index, doc_type):
        self.m_es = es
        self.m_index = index
        self.m_doc_type = doc_type

    def query_all(self):
        query = {'query': {'match_all': {}}}
        query_res = self.m_es.search(self.m_index, self.m_doc_type, query)
        return query_res

    def query_match(self, age):
        query = {'query': { \
                    'match': { \
                        'age': age }}}
        query_res = self.m_es.search(self.m_index, self.m_doc_type, query)
        return query_res

    def query_range(self, age_sta = None, age_end = None):
        query = {}
        if None == age_sta and None == age_end:
            return None
        elif None == age_sta:
            query = {'query': { \
                        'range': { \
                            'age': { \
                                'gte': age_sta }}}}
        elif None == age_end:
            query = {'query': { \
                        'range': { \
                            'age': { \
                                'gte': age_sta }}}}
        else:
            query = {'query': { \
                        'range': { \
                            'age': { \
                                'gte': age_sta,
                                'lte': age_end }}}}

        query_res = self.m_es.search(self.m_index, self.m_doc_type, query)

        return query_res
