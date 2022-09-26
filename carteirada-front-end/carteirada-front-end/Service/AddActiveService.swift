//
//  AddActiveService.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 25/09/22.
//

import Foundation
import Alamofire

class AddActiveService {
    func postActive(email: String, active: String, date: Date, ticker: String, quantity: Int, price: Float, sucess: @escaping (User)-> Void,error: @escaping (Error)-> Void) {
        var parameter =  [String:Any]()
        parameter["email"] = email
        parameter["active"] = active
        parameter["date"] = date
        parameter["ticker"] = ticker
        parameter["quantity"] = quantity
        parameter["price"] = price
        
        NetworkService.request(url: "https://carteirada-back-end-production.up.railway.app/user", method: .post, params: parameter, obj: User.self) { result in
            sucess(result)
        } error: { e in
            error(e)
        }
    }
}
