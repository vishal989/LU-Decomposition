#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


# In[2]:


serial = pd.read_csv("serialOutput.txt")
openMP = pd.read_csv("openMPOutput.txt")
pThread = pd.read_csv("pThreadOutput.txt")


# In[3]:


serial.info()


# In[4]:


openMP.info()


# In[5]:


serial.describe()


# In[6]:


serial.head(10)


# In[7]:


openMP.head(10)


# In[8]:


pThread.head(10)


# In[ ]:


sns.set_style("darkgrid")
plt.figure(figsize = (15, 6))
plt.plot(serial["size"].head(19),serial["sec"].head(19),marker="o")
plt.plot(openMP["size"].head(16),openMP["sec"].head(16),marker="o")
plt.plot(pThread["size"].head(19),pThread["sec"].head(19),marker="o")
plt.ylabel("Time in milliseconds", fontsize = 16)
plt.xlabel("Matrix size", fontsize= 16)
plt.legend(["serial","openMP","pThread"]);
plt.show()

# In[ ]:




