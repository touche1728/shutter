import http.client

conn = http.client.HTTPSConnection("aerisweather1.p.rapidapi.com")

headers = {
    'x-rapidapi-host': "aerisweather1.p.rapidapi.com",
    'x-rapidapi-key': "0f5f2241d8msh3dc553f7c2e026ap1011a6jsn5509553ca852"
    }

conn.request("GET", "/observations/somerset,nj", headers=headers)
# conn.request("GET", "/sunmoon/somerset,nj", headers=headers)

res = conn.getresponse()
data = res.read()

# res2 = conn.getresponse()
# data2 = res.read()


# print(data.decode("utf-8"))
print(type(data))
