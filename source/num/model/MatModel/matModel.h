//
// Created by 24100 on 2022/4/19.
//

#ifndef NUM_MAT4MODEL_H
#define NUM_MAT4MODEL_H
#include <QAbstractTableModel>
#include <Eigen/Dense>

class matModel : public QAbstractTableModel
{
public:
	explicit matModel(QObject *parent = nullptr);
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole) override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;


public slots:
	/**
	 * @brief 设置矩阵大小
 	*/
	void setMatSize(int row,int col);
	/**
	 * @brief 让视图view更新数据
	 */
	void updateMat();
public:
	Eigen::MatrixXd mat;
};


#endif //NUM_MAT4MODEL_H
